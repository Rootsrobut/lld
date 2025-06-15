#include<iostream>
#include<vector>
using namespace std;

void printData(const vector<int>& data) {
    // Attempting to modify data here would result in a compilation error
    // data[0] = 100; // Uncommenting this line will cause an error
      for (int value : data) {
        cout << value << " ";
    }
    cout<<endl;
}

int main()
{
    vector<int> myData = {1, 2, 3, 4, 5};
    printData(myData);
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    int* studentIds = new int[numberOfStudents];
    for (int i = 0; i < numberOfStudents; ++i) {
        studentIds[i] = i + 1;
    }
    cout << "Student IDs: ";
    for (int i = 0; i < numberOfStudents; ++i) {
        if(i%5==0) cout << studentIds[i] << " ";
    }
    cout <<endl;
    delete[] studentIds;


    int stackArray[5] = {1, 2, 3, 4, 5};
    cout << "Size of stackArray: " << sizeof(stackArray) << " bytes" << endl;
    cout << "Number of elements in stackArray: " << sizeof(stackArray) / sizeof(stackArray[0]) << endl;

    int* dynamicArray = new int[1000];
    cout << "Size of dynamicArray pointer: " << sizeof(dynamicArray) << " bytes" << endl; // Note: sizeof(dynamicArray) only gives the size of the pointer, not the allocated memory
    return 0;
}




