// Inheritence -> Inheritance allows one class (called the subclass or child class) to inherit the properties 
// and behaviors of another class (called the superclass or parent class).

#include<iostream>
using namespace std;

class Car {
protected:
    const char* make;
    const char* model;

public:
    void startEngine() {
        printf("Engine started\n");
    }

    void stopEngine() {
        printf("Engine stopped\n");
    }
};

class ElectricCar : public Car {
public:
    void chargeBattery() {
        printf("Battery charging\n");
    }
};

// Subclass for gas cars
class GasCar : public Car {
public:
    void fillTank() {
        printf("Filling gas tank\n");
    }
};


// Use inheritance when:
// There is a clear "is-a" relationship (e.g., Dog is an Animal, Car is a Vehicle)

// many modern OOP designs favor composition over inheritance for better modularity and flexibility.