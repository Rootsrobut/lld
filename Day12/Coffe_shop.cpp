#include <iostream>
using namespace std;

// Component
class Coffee {
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() = default;
};

// ConcreteComponent
class SimpleCoffee : public Coffee {
public:
    string getDescription() const override {
        return "Simple Coffee";
    }
    double getCost() const override {
        return 5.0;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;  // Raw pointer
public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}
    string getDescription() const override {
        return decoratedCoffee->getDescription();
    }
    double getCost() const override {
        return decoratedCoffee->getCost();
    }
    virtual ~CoffeeDecorator() {
        delete decoratedCoffee;  // Clean up
    }
};

// ConcreteDecorators
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* coffee) : CoffeeDecorator(coffee) {}
    string getDescription() const override {
        return decoratedCoffee->getDescription() + ", Milk";
    }
    double getCost() const override {
        return decoratedCoffee->getCost() + 1.0;
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* coffee) : CoffeeDecorator(coffee) {}
    string getDescription() const override {
        return decoratedCoffee->getDescription() + ", Sugar";
    }
    double getCost() const override {
        return decoratedCoffee->getCost() + 0.5;
    }
};

int main() {
    Coffee* myCoffee = new SimpleCoffee();  // base coffee
    myCoffee = new Milk(myCoffee);          // add milk
    myCoffee = new Sugar(myCoffee);         // add sugar

    cout << "Order: " << myCoffee->getDescription() << endl;
    cout << "Cost: $" << myCoffee->getCost() << endl;

    delete myCoffee;  // Clean up all dynamically allocated memory
    return 0;
}
