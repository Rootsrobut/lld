#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    vector<int>v(5);
    for(int i=0;i<5;i++) cin>>v[i];
    ofstream fout;
    fout.open("zoom.txt");
    fout<<"original data\n";
    for(int i=0;i<5;i++){fout<<v[i]<<" ";}
    sort(v.begin(),v.end());
    fout<<"\n";
    fout<<"sortedata data\n";
    for(int i=0;i<5;i++){fout<<v[i]<<" ";}
    fout.close();
    return 0;
}