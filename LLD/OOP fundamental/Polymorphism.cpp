// Polymorphism -> Polymorphism allows the same method name or interface to exhibit different behaviors 
// depending on the object that is invoking it.

// The term "polymorphism" comes from Greek and means "many forms." In programming, it allows us to write 
// code that is generic, extensible, and reusable, while the specific behavior is determined at runtime or 
// compile-time based on the object’s actual type.

#include<iostream>
using namespace std;

// Two Types of Polymorphism

//.............................................1 -> Compile-time Polymorphism (Static Binding)..................................................

// Also known as method overloading, compile-time polymorphism occurs when:

// You have multiple methods with the same name in the same class.
// Each method has a different parameter list (number, type, or order).
// The method to call is decided at compile time, based on the arguments passed.

class Calculator {
    public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
};




//.............................................2 -> Runtime Polymorphism (Dynamic Binding)..................................................

// Also known as method overriding, this happens when:

// A subclass overrides a method defined in its superclass or interface.
// The method to invoke is determined at runtime, based on the actual object type.

class NotificationSender {
public:
    virtual void sendNotification(const string& message) = 0;  // pure virtual function
};

class EmailSender : public NotificationSender {
public:
    void sendNotification(const string& message) override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

class SmsSender : public NotificationSender {
public:
    void sendNotification(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};


void notifyUser(NotificationSender* sender, const string& message) {
    sender->sendNotification(message);
}

// This is runtime polymorphism, where the decision of which method to execute is made during execution, 
// not at compile time.

