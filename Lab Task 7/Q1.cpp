#include <iostream>
using namespace std;

class Account{
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string num, double bal, string name, string type = "") : accountNumber(num), balance(bal), accountHolderName(name), accountType(type) {}

    virtual void deposit(double amount){
        balance += amount;
        cout << "The amount $" << amount << " has been deposited into your account." << endl;
        cout << "Remaining balance: $" << balance << endl;
    }

    virtual void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
            cout << "The amount $" << amount << " has been withdrawn from your account." << endl;
            cout << "Remaining balance: $" << balance << endl;
        }
        else{
            cout << "Amount $" << amount << " exceeds your account balance." << endl;
        }
    }

    virtual double calculateInterest(){ return 0.0; }  // Empty method, to be overriden in derived classes
    virtual void printStatement(){}  // Empty method, to be overriden in derived classes

    virtual void getAccountInfo(){
        cout << "Displaying account information below" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: $" << balance << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << ((accountType != "") ? accountType : "Optional") << endl;
    }
};

class SavingsAccount : public Account{
    const double interestRate;
    double minimumBalance;

public:
    SavingsAccount(double rate, double minBal, string num, double bal, string name, string type = "") :  interestRate(rate), minimumBalance(minBal), Account(num, bal, name, type){
        if(balance < minimumBalance){
            do{
                cout << "The entered balance ($" << balance << ") is less than the minimum balance ($" << minimumBalance << "). Enter account balance again: ";
                cin >> balance; 
            } while(balance < minimumBalance);
        }
    }

    double calculateInterest() override {
        return (balance * interestRate);
    }

    void withdraw(double amount) override {
        if(balance - amount >= minimumBalance){
            balance -= amount;
            cout << "The amount $" << amount << " has been withdrawn from your account." << endl;
            cout << "Remaining balance: $" << balance << endl;
        }
        else if(amount > balance){
            cout << "Amount $" << amount << " exceeds your account balance." << endl;
        }
        else{
            cout << "Cannot withdraw. Minimum balance of $" << minimumBalance << " is required for savings account." << endl;
        }
    }

    void printStatement() override {
        cout << "--------- Savings Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to calculate interest for." << endl;
        cout << "Enter 4 to exit" << endl;

        int choice;
        do{
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice){
                case 1: {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    deposit(amount);
                    break;
                }

                case 2: {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    withdraw(amount);
                    break;
                }

                case 3:
                    cout << "The interest rate of Savings Account is " << interestRate << "/" << (100 * interestRate) << "%" << endl;
                    cout << "Interest Amount is: $" << calculateInterest() << endl;
                    break;

                case 4:
                    cout << "Exiting savings account..." << endl;
                    break;
                
                default:
                    cout << "Invalid Input, try again." << endl;
            }
        } while(choice != 4);
        getAccountInfo();
    }
};

int main(){
    Account *a = new SavingsAccount(0.10, 500, "24K-0687", 200 , "Rayyan Aamir", "Savings");
    a->printStatement();
    return 0;
}
