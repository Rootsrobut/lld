
#include<iostream>
using namespace std;

void nullPointerDereference() {
    int* ptr = nullptr; // Null pointer
    // Uncommenting the next line will cause a segmentation fault
    *ptr = 10; 
    cout << ptr << endl;
}

void memoryLeak() {
    int* arr = new int[1000]; // Dynamically allocated array
    // Forgetting to delete arr leads to a memory leak
    // delete[] arr; // Uncomment to fix the leak
}

int* danglingPointer() {
    int result = 42; // Local variable
    return &result; // Returning address of a local variable (dangling pointer)
}
void doubleFree() {
    int* x = new int(10);
    delete x; // First delete
    // Uncommenting the next line will cause a double free error
    // delete x; // Second delete
}
int main()
{
    
   //nullPointerDereference();
    // memoryLeak();
    //int* ptr = danglingPointer(); // ptr is now dangling
    //cout << *ptr << endl; // Dereferencing dangling pointer
    //doubleFree();
    return 0;
}
