#include <iostream>
#include <string>
#include <map>
using namespace std;

// Memento - Stores database state snapshot
class DatabaseMemento {
private:
    map<string, string> data;
public:
    DatabaseMemento(const map<string, string>& dbData) : data(dbData) {}
    map<string, string> getState() const {
        return data;
    }
};

// Originator - The database whose state we want to save/restore
class Database {
private:
    map<string, string> records;
public:
    // Insert a record
    void insert(const string& key, const string& value) {
        records[key] = value;
        cout << "Inserted: " << key << " = " << value << endl;
    }

    // Update a record
    void update(const string& key, const string& value) {
        if (records.find(key) != records.end()) {
            records[key] = value;
            cout << "Updated: " << key << " = " << value << endl;
        } else {
            cout << "Key not found: " << key << endl;
        }
    }

    // Delete a record
    void remove(const string& key) {
        auto it = records.find(key);
        if (it != records.end()) {
            records.erase(it);
            cout << "Deleted: " << key << endl;
        } else {
            cout << "Key not found for deletion: " << key << endl;
        }
    }

    // Create memento - Save current state
    DatabaseMemento* createMemento() {
        cout << "Creating database backup..." << endl;
        return new DatabaseMemento(records);
    }

    // Restore from memento - Rollback to saved state
    void restoreFromMemento(const DatabaseMemento& memento) {
        records = memento.getState();
        cout << "Database restored from backup!" << endl;
    }

    // Display current database state
    void displayRecords() const {
        cout << "\n--- Current Database State ---" << endl;
        if (records.empty()) {
            cout << "Database is empty" << endl;
        } else {
            for (const auto& record : records) {
                cout << record.first << " = " << record.second << endl;
            }
        }
        cout << endl;
    }
};

// Caretaker - Manages the memento (Transaction Manager)
class TransactionManager {
private:
    DatabaseMemento* backup;
public:
    TransactionManager() : backup(nullptr) {}

    ~TransactionManager() {
        if (backup) {
            delete backup;
        }
    }

    // Begin transaction - create backup
    void beginTransaction(Database& db) {
        cout << "\n=== BEGIN TRANSACTION ===" << endl;
        if (backup) {
            delete backup;
        }
        backup = db.createMemento();
    }

    // Commit transaction - discard backup
    void commitTransaction() {
        cout << "=== COMMIT TRANSACTION ===" << endl;
        if (backup) {
            delete backup;
            backup = nullptr;
        }
        cout << "Transaction committed successfully!" << endl;
    }

    // Rollback transaction - restore from backup
    void rollbackTransaction(Database& db) {
        cout << "=== ROLLBACK TRANSACTION ===" << endl;
        if (backup) {
            db.restoreFromMemento(*backup);
            delete backup;
            backup = nullptr;
            cout << "Transaction rolled back!" << endl;
        } else {
            cout << "No backup available for rollback!" << endl;
        }
    }
};

// Main function
int main() {
    Database db;
    TransactionManager txManager;

    // Success scenario
    txManager.beginTransaction(db);
    db.insert("user1", "Aditya");
    db.insert("user2", "Rohit");
    txManager.commitTransaction();
    db.displayRecords();

    // Failed scenario
    txManager.beginTransaction(db);
    db.insert("user3", "Saurav");
    db.insert("user4", "Manish");

    // Simulate error - rollback
    cout << "ERROR: Something went wrong during transaction!" << endl;
    txManager.rollbackTransaction(db);
    db.displayRecords();

    return 0;
}


// DatabaseMemento = snapshot holder.
// Database = originator,
// TransactionManager = caretaker that manages the snapshot.