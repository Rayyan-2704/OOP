#include <iostream>
#include <string>
using namespace std;

class PaymentMethod{
public:
    virtual bool processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod{
    string cardNumber;

public:
    CreditCard(const string &c) : cardNumber(c) {}

    bool processPayment(double amount) override {
        if(cardNumber.length() != 16 || amount <= 0){
            cout << "Credit Card payment failed. Invalid credit card number or amount." << endl;
            return false;
        }

        cout << "Credit Card payment of $" << amount << " using card number " << cardNumber << " has been proceeded successfully!" << endl;
        return true;
    }
};

class DigitalWallet : public PaymentMethod{
    double balance;

public:
    DigitalWallet(double bal) : balance(bal) {}

    bool processPayment(double amount) override {
        if(balance < amount){
            cout << "Payment cancelled as insufficient balance." << endl;
            return false;
        }

        balance -= amount;
        cout << "Digital Wallet payment of $" << amount << " has been proceeded successfully." << endl;
        cout << "New Balance: $" << balance << endl;
        return true;
    }
};

int main(){
    CreditCard card("2406871234038294");
    DigitalWallet wallet(250.25);

    cout << endl << "Payment 1: Using Credit Card" << endl;
    cout << ((card.processPayment(150.47)) ? "Payment successful!" : "Payment failed!") << endl;

    cout << endl << "Payment 2: Using Digital Wallet" << endl;
    cout << ((wallet.processPayment(100.0)) ? "Payment successful!" : "Payment failed!") << endl;

    cout << endl << "Payment 3: Using Digital Wallet" << endl;
    cout << ((wallet.processPayment(400.0)) ? "Payment successful!" : "Payment failed!") << endl;

    return 0;
}