#include<iostream>
#include<string>
using namespace std;
// real life car

// Abstraction  Encapsulation

class Car{  //  1.abstract class :: ? Error: cannot create of instantiate abstract class -->may/maynot 2. Atleast one methord is incomplete or virtual methord 
	public:
		virtual void startEngine()=0;
		virtual void shiftGear(int gear)=0;
		virtual void accelerate()=0;
		virtual void brake()=0;
		virtual void stopEngine()=0;
		virtual ~Car(){}
};

class SportsCar:public Car{
	public:
		string brand;
		string model;
		bool isEngineOn;
		int currentspeed;
		int currentgear;
	SportsCar(string b,string m){
		this->brand=b;
		this->model=m;
		isEngineOn=false;
		currentspeed=0;
		currentgear=0;
	}
	void startEngine() override{
		isEngineOn=true;
		cout<<brand<<" "<<model<<" : Engine starts with a roar!"<<endl;
	}
	void shiftGear(int gear) override{
		if(!isEngineOn){
			cout<<brand<<" "<<model<<" : Engine is off:Cannot Shift Gear"<<endl;
			return;
		}
		else{
          currentgear=gear;
		  cout<<brand<<" "<<model<<"Shifted to Gear "<<currentgear<<endl;

		}
		
	}
	void accelerate() override{
		if(!isEngineOn){
			cout<<brand<<" "<<model<<" : Engine is off:Cannot Accelerate."<<endl;
			return;
		}
		else{
		  currentspeed += 10 * currentgear;
		  cout<<brand<<" "<<model<<":Accelerating to "<<currentgear<<endl;
		}
	}
	void brake() override{
		if (currentspeed > 0) {
            currentspeed -= 10;
            if (currentspeed < 0) currentspeed = 0;
            cout << brand << " " << model << " is braking. Speed: " << currentspeed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
	}
	void stopEngine() override{
		if (isEngineOn) {
            isEngineOn = false;
            currentspeed = 0;
            currentgear = 0;
            cout << brand << " " << model << " : Engine stopped." << endl;
        } else {
            cout << brand << " " << model << " : Engine is already off." << endl;
        }
	}
};


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	SportsCar myCar("Ferrari", "488 GTB");
    myCar.startEngine();
    myCar.shiftGear(2);
    myCar.accelerate();
    myCar.brake();
    myCar.stopEngine();
	return 0;
}