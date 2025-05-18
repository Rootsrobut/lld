#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero error!");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        cout << "Result: " << result <<endl;
    } catch (const runtime_error& error) {
        cerr << "Error: " << error.what() <<endl;
    }
    return 0;
}