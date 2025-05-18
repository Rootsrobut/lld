#include <iostream>
#include <fstream>



using namespace std;

int main() {
    ifstream file("example.txt");
    if (file.fail()) {
        cerr << "Error opening file." <<endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        cout << line << std::endl;
    }
    if (file.bad()) {
        cerr << "Error during reading." <<endl;
    }
    if (file.eof()) {
        cout << "End of file reached." << endl;
    }
    file.close();
    return 0;
}