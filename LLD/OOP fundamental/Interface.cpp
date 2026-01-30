// Interface -> At its core, an interface is a contract: a list of methods that any implementing class must provide. 
// It specifies a set of behaviors that a class agrees to implement but leaves the details of those behaviors up to each implementation.

// In other words:
// An interface defines the "what", while classes provide the "how".

#include<iostream>
using namespace std;

class PaymentGateway {
public:
    virtual void initiatePayment(double amount) = 0;  // Pure virtual function
    virtual ~PaymentGateway() {}  // Virtual destructor for proper cleanup
};

class StripePayment : public PaymentGateway {
public:
    void initiatePayment(double amount) override {
        cout << "Processing payment via Stripe: $" << amount << endl;
    }
};

class RazorpayPayment : public PaymentGateway {
public:
    void initiatePayment(double amount) override {
        cout << "Processing payment via Razorpay: ₹" << amount << endl;
    }
};

class CheckoutService {
private:
    PaymentGateway* paymentGateway;

public:
    CheckoutService(PaymentGateway* gateway) : paymentGateway(gateway) {}
    
    void setPaymentGateway(PaymentGateway* gateway) {
        paymentGateway = gateway;
    }
    
    void checkout(double amount) {
        if (paymentGateway != nullptr) {
            paymentGateway->initiatePayment(amount);
        }
    }
};


int main() {
    StripePayment stripeGateway;
    CheckoutService service(&stripeGateway);
    service.checkout(120.50);  // Output: Processing payment via Stripe: $120.5
    
    // Switch to Razorpay
    RazorpayPayment razorpayGateway;
    service.setPaymentGateway(&razorpayGateway);
    service.checkout(150.50);  // Output: Processing payment via Razorpay: ₹150.5
  
    return 0;
}