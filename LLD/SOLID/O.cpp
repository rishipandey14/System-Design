// O -> Open for extension but closed for modification

#include<iostream>
using namespace std;


// introduce an abstraction for the payment methods.

// Step 1: Define an Interface (or an Abstract Class)
// We'll create a PaymentMethod interface that defines a contract for all payment types:

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() = default;
};


// Step 2: Implement Concrete Strategies
// Now, for each payment type, we create a separate class that implements this interface:


class CreditCardPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "processing Credit card payment of $" << amount << endl;
        // logic for credit card payment
    }
};



class PaypalPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "processing Paypal payment of $" << amount << endl;
        // logic for Paypal payment
    }
};



class UPIPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "processing UPI payment of $" << amount << endl;
        // logic for UPI payments
    }
};


class PaymentProcessor {
public:
    void process(PaymentMethod* paymentMethod, double amount){
        // no more if-else! The processor doesn't care about the specific type.
        // it just knows it can call processPayment
        paymentMethod->processPayment(amount);
    }
};


class CheckoutService {
public:
    void processPayment(PaymentMethod* method, double amount){
        PaymentProcessor processor;
        processor.process(method, amount);
    }
};



void demoO(){
    CheckoutService checkout;
    CreditCardPayment creditCard;
    PaypalPayment paypal;
    UPIPayment upi;

    checkout.processPayment(&creditCard, 100.00);
    // checkout.processPayment(&upi, 100.00);
    // checkout.processPayment(&paypal, 100.00);
}