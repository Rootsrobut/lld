#include <iostream>
#include <exception>
#include <string>


using namespace std;

class MyException : public exception {
public:
    MyException(const string& message) : message_(message) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    string message_;
};

int main() {
    try {
        throw MyException("Custom exception occurred!");
    } catch (const MyException& exception) {
        cerr << "Caught exception: " << exception.what() << endl;
    }
    return 0;
}