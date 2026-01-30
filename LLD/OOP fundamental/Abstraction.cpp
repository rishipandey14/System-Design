// Abstraction -> Abstraction is the process of hiding complex internal implementation details and exposing only the relevant, 
// high-level functionality to the outside world. 

// Abstraction = Hiding Complexity + Showing Essentials

#include<iostream>
using namespace std;

// How Abstraction Is Achieved


// ........................................................1 -> Abstract classes.................................................................

class Vehicle {
    protected:
    string brand;
    
    public:
    // constructor
    Vehicle(string brand) : brand(brand) {}
    
    // abstract method (pure virtual function)
    virtual void start() = 0;
    
    // concrete method (can be inherited)
    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }
    
    // destructor
    virtual ~Vehicle() {}
};

// subclass implementing the abstract method
class Car : public Vehicle {
    public:
    Car(string brand) : Vehicle(brand) {}
    
    void start() override {
        cout << "Car is starting..." << endl;
    }
};







// ........................................................2 -> Interfaces .................................................................

class Document {
    private:
    string content;
    
    public:
    Document(string content) : content(content) {}
    
    string getContent() {
        return content;
    }
};

// Interface (pure abstract class)
class Printable {
    public:
    virtual void print(Document doc) = 0;
    virtual ~Printable() {}
};

// Concrete implementation of Printable
class PDFPrinter : public Printable {
    public:
    void print(Document doc) override {
        cout << "Printing PDF: " << doc.getContent() << endl;
    }
};

class InkjetPrinter : public Printable {
    public:
    void print(Document doc) override {
        cout << "Printing via Inkjet: " << doc.getContent() << endl;
    }
};






// ........................................................3 -> Public APIs .................................................................

// Even when you're not using abstract classes or interfaces, 
// abstraction is achieved through clean, public APIs that expose only what's necessary.

class DatabaseClient {
public:
    void connect() {
        // ...
    }
   
    void query(string sql) {
        // ...
    }
   
private:
    void openSocket() {
        // internal logic
    }
    
    void authenticate() {
        // internal logic
    }
};


// Explanation
// Users only see connect() and query() — a simple, high-level API.
// They don’t see or care about low-level socket handling or authentication logic.
// The interface remains clean, while the internal implementation can evolve freely.