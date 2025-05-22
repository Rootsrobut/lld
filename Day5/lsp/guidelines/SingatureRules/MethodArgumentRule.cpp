#include<iostream>
using namespace std;




class Parent{
    public:
    virtual void printMsg(string msg){
        cout<<"parent : "<<msg<<endl;
    }
};

class Child:public Parent{
    public:
    void printMsg(string msg) override{
        cout<<"child: "<<msg<<endl;
    }
};

class Client{
    private:
          Parent* p;
    public:
    Client(Parent* p){
        p->printMsg("Hello");
    }      
};



int main()
{

    Parent* parent=new Parent();
    Child* child=new Child();
    Client* client=new Client(child);
    return 0;
}