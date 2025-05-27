#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    //File ko open karna
    ofstream fout;
    fout.open("zoom.txt"); // if file not prasent create kar dega aur fir open kar dega
    // write kar sakta hu
    fout<<"I love My country";
    fout.close(); // resource release kar paauo
    return 0;
}