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
        if(amount > 0){
            balance += amount;
            cout << "The amount $" << amount << " has been deposited into your account." << endl;
            cout << "Remaining balance: $" << balance << endl;
        }
        else{
            cout << "Invalid amount entered." << endl;
        }
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
        cout << endl << "Displaying account information below" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: $" << balance << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << ((accountType != "") ? accountType : "-") << endl;
    }
};

class SavingsAccount : public Account{
    const double interestRate;
    double minimumBalance;

public:
    SavingsAccount(double rate, double minBal, string num, double bal, string name, string type = "Savings Account") :  interestRate(rate), minimumBalance(minBal), Account(num, bal, name, type){
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
        cout << endl << "--------- Savings Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to calculate interest for." << endl;
        cout << "Enter 4 to get account information." << endl;
        cout << "Enter 5 to exit." << endl;

        int choice;
        do{
            cout << endl << "Enter your choice: ";
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
                    cout << "The interest rate of Savings Account is " << interestRate << "(" << (100 * interestRate) << "%)" << endl;
                    cout << "Interest Amount is: $" << calculateInterest() << endl;
                    break;

                case 4:
                    getAccountInfo();
                    break;

                case 5:
                    cout << "Exiting Savings Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while(choice != 5);
    }
};

class CheckingAccount : public Account{
public:
    CheckingAccount(string num, double bal, string name, string type = "Checking Account") : Account(num, bal, name, type) {}

    void printStatement() override {
        cout << endl << "--------- Checking Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to get account information." << endl;
        cout << "Enter 4 to exit." << endl;

        int choice;
        do{
            cout << endl << "Enter your choice: ";
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
                    getAccountInfo();
                    break;

                case 4:
                    cout << "Exiting Checking Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while(choice != 4);
    }    
};

class FixedDepositAccount : public Account{
    string maturityDate;
    const double fixedInterestRate;

public:
    FixedDepositAccount(string date, double rate, string num, double bal, string name, string type = "Fixed Deposit Account") :  maturityDate(date), fixedInterestRate(rate), Account(num, bal, name, type) {}

    void withdraw(double amount) override {
        string currentDate;
        cout << "Enter today's date: ";
        cin >> currentDate;

        if(currentDate == maturityDate){
            Account :: withdraw(amount);
        }
        else{
            cout << "Cannot withdraw amount before maturity date from a Fixed Deposit Account." << endl;
        }
    }

    double calculateInterest() override {
        return (balance * fixedInterestRate);
    }

    void printStatement() override {
        cout << endl << "--------- Fixed Deposit Account Menu ---------" << endl;
        cout << "Enter 1 to deposit money." << endl;
        cout << "Enter 2 to withdraw money." << endl;
        cout << "Enter 3 to calculate interest for." << endl;
        cout << "Enter 4 to get account information." << endl;
        cout << "Enter 5 to exit." << endl;

        int choice;
        do{
            cout << endl << "Enter your choice: ";
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
                    cout << "The fixed interest rate of Fixed Deposit Account is " << fixedInterestRate << "(" << (100 * fixedInterestRate) << "%)" << endl;
                    cout << "Interest Amount is: $" << calculateInterest() << endl;
                    break;

                case 4:
                    getAccountInfo();
                    break;

                case 5:
                    cout << "Exiting Fixed Deposit Account..." << endl;
                    break;
                
                default:
                    cout << "Invalid input, try again!" << endl;
            }
        } while(choice != 5);
    }
};

int main(){
    Account *a = nullptr;
    string name, number;
    double bal;
    cout << "-------------- Welcome to Account System --------------" << endl;
    cout << "Enter your account number: ";
    getline(cin, number);
    cout << "Enter your account holder name: ";
    getline(cin, name);
    cout << "Enter your account balance: ";
    cin >> bal;
    cin.ignore();
    
    char input;
    cout << "Enter your account type ('S' for Savings Account, 'C' for Checking Account, 'F' for Fixed Deposit Account): ";
    cin >> input;
    switch(input){
        case 'S':
        case 's':
        {
            double minBal, rate;
            cout << "Enter the minimum balance of your Savings Account: ";
            cin >> minBal;
            cout << "Enter the interest rate of your Savings Account: ";
            cin >> rate;
            a = new SavingsAccount(rate, minBal, number, bal, name);
            break;
        }

        case 'C':
        case 'c':
            a = new CheckingAccount(number, bal, name);
            break;

        case 'F':
        case 'f':
        {
            double rate;
            string mDate;
            cout << "Enter the maturity date of your Fixed Deposit Account: ";
            cin >> mDate;
            cout << "Enter the fixed interest rate of your Fixed Deposit Account: ";
            cin >> rate;
            a = new FixedDepositAccount(mDate, rate, number, bal, name);
            break;
        }

        default:
            cout << "Invalid input, try again!" << endl;
    }

    if(a != nullptr){
        a->printStatement();
    }
    delete a;
    return 0;
}
