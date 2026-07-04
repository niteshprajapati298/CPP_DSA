#include <iostream>
#include <string>
using namespace std;

// LSP: Liskov Substitution Principle
// Derived payment classes can replace the base payment type without breaking behavior.
//
// Bad example idea:
// A subclass that throws an exception or behaves differently when used as a payment method.
// That breaks the expectation of the base class contract.
//
// Example:
// class CashPayment : public PaymentMethod {
// public:
//     void pay(double amount) override { /* ... */ }
//     void refund(double amount) override { throw runtime_error("Not supported"); }
// };

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual void pay(double amount) = 0;
    virtual void refund(double amount) = 0;
};

class CreditCardPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Credit card charged: " << amount << endl;
    }

    void refund(double amount) override {
        cout << "Credit card refund: " << amount << endl;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "PayPal charged: " << amount << endl;
    }

    void refund(double amount) override {
        cout << "PayPal refund: " << amount << endl;
    }
};

class PaymentController {
private:
    PaymentMethod& paymentMethod;

public:
    explicit PaymentController(PaymentMethod& method)
        : paymentMethod(method) {}

    void charge(double amount) {
        paymentMethod.pay(amount);
    }

    void cancel(double amount) {
        paymentMethod.refund(amount);
    }
};

int main() {
    CreditCardPayment card;
    PaymentController cardController(card);
    cardController.charge(300.0);
    cardController.cancel(100.0);

    PayPalPayment paypal;
    PaymentController paypalController(paypal);
    paypalController.charge(250.0);

    return 0;
}
