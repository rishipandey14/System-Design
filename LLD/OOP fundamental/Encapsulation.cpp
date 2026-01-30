// Encapsulation -> In a well-encapsulated design, external code doesn’t need to know how something is done, 
// it only needs to know what can be done.

// Encapsulation = Data hiding + Controlled access

#include<iostream>
using namespace std;

class PaymentProcessor {
private:
   string cardNumber;
   double amount;

   string maskCardNumber(string cardNumber) {
       return "****-****-****-" + cardNumber.substr(cardNumber.length() - 4);
   }

public:
   PaymentProcessor(string cardNumber, double amount) {
       this->cardNumber = maskCardNumber(cardNumber);
       this->amount = amount;
   }

   void processPayment() {
       cout << "Processing payment of " << amount << " for card " << cardNumber << endl;
   }
};

int main() {
   PaymentProcessor payment("1234567812345678", 250.00);
   payment.processPayment();
   return 0;
}