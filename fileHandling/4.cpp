#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout;
    fout.open("21.txt");
    fout << "Hello India\n";
    fout << "Hello Rohit\n";
    fout << "Hello Bhai\n";
    fout.close();

    ifstream fin;
    fin.open("21.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
