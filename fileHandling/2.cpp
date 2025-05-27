#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    // file ko open karo
    fin.open("zoom.txt");
    // fr read karo
    char c;
    //fin>>c;
    c=fin.get(); // read space also
    while(!fin.eof()){
        cout<<c;
        c=fin.get();
    }
    fin.close();
    return 0;
}