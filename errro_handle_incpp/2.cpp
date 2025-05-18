#include <iostream>
#include <fstream>


using namespace std;

int readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 1; 
    }
    file.close();
    return 0; 
}

int main() {
    int result = readFile("example.txt");
    if (result != 0) {
        cerr << "Error reading file. Error code: " << result <<endl;
    } else {
        cout << "File read successfully." << endl;
    }
    return 0;
}