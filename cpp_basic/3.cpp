#include<iostream>
#include <string>
#include <utility> // For std::move


using namespace std;

int main()
{
    
    // Lvalue example
    int i = 10; // 'i' is an lvalue
    cout << "Original i: " << i << endl;
    // Lvalue reference
    int& lref = i; // lref is an lvalue reference to i
    lref = 20; // Modify i through lref
    cout << "Modified i through lref: " << i << endl;
    // Rvalue example
    int&& rref = 30; // rref is an rvalue reference to a temporary value
    cout << "Rvalue reference rref: " << rref << endl;





    string myString = "A long string here";
    // Move the string to a new variable
    string newValue =move(myString);

    // Output the results
    cout << "Original string (after move): " << myString << endl; // myString is now empty
    cout << "New string: " << newValue << endl; // newValue has the original string


    // Demonstrating move assignment
    string anotherString = "Another long string";
    anotherString =move(newValue); // Move assignment
    cout << "Another string (after move assignment): " << anotherString << endl; // anotherString has the value
    cout << "New value (after move assignment): " << newValue << endl; 
    return 0;
}