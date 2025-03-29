/* A bank provides different types of accounts, such as Savings Account and Current Account. Each account has a method to calculate the annual interest, but the formula differs for different account types.
Additionally, the bank allows overloading the deposit method to handle different types of deposits (cash, check, online transfer). The withdraw method is overridden to implement specific rules for different accounts.
Moreover, the bank maintains customer balances in an object, and it supports operator overloading for addition (+), subtraction (-), multiplication (*), and division (/) to handle balance calculations efficiently.
Task Requirements:
1. Create a base class BankAccount with attributes like accountNumber, balance, and a virtual function calculateInterest().
2. Implement two derived classes:
   ---> SavingsAccount (Interest: 5% per year)
   ---> CurrentAccount (Interest: No interest)
3. Overload the deposit method in both derived classes to handle:
   ---> Deposit via cash
   ---> Deposit via check
   ---> Deposit via online transfer
4. Override the withdraw method in both derived classes with different rules:
   ---> SavingsAccount: Cannot withdraw if balance is below $500
   ---> CurrentAccount: Allows overdraft up to $1000
5. Implement operator overloading in BankAccount:
   ---> + to add two account balances
   ---> - to subtract an amount from balance
   ---> * to apply interest on balance
   ---> / to calculate equal installment payments from balance
6. Create objects of both SavingsAccount and CurrentAccount, demonstrate method overloading, overriding, and operator overloading with real transaction examples. */

#include <iostream>
using namespace std;

class BankAccount{
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string num, double bal) : accountNumber(num), balance(bal) {}

    virtual void calculateInterest() { cout << "Function to be overriden in derived classes" << endl; }

    virtual void withdraw(double amount){
        if(amount > balance){
            cout << "Cannot withdraw amount $" << amount << " as it exceeds the account balance." << endl;
            return;
        }
        balance -= amount;
        cout << "Amount $" << amount << " withdrawn successfully. New balance: $" << balance << endl;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Amount $" << amount << " deposited via cash. New balance: $" << balance << endl;
    }

    void deposit(double amount, string checkNumber){
        balance += amount;
        cout << "Amount $" << amount << " deposited via check (" << checkNumber << "). New balance: " << balance << endl;
    }

    void deposit(double amount, string transferBankName, string transferAccNum){
        balance += amount;
        cout << "Amount $" << amount << " deposited via online transfer from " << transferBankName << " by account number " << transferAccNum << ". New balance: $" << balance << endl; 
    }

    void displayDetails() const {
        cout << endl << "Account Number: " << accountNumber << " | Balance: $" << balance << endl;
    }

    BankAccount operator + (const BankAccount &other){
        return BankAccount(accountNumber, balance + other.balance);
    }

    BankAccount operator - (double amount){
        return BankAccount(accountNumber, balance - amount);
    }

    BankAccount operator * (double interestRate){
        return BankAccount(accountNumber, balance * (1 + interestRate / 100));
    }

    BankAccount operator / (int installments){
        return BankAccount(accountNumber, balance / installments);
    }
};

class SavingsAccount : public BankAccount{
public:
    SavingsAccount(string num, double bal) : BankAccount(num, bal) {}

    void calculateInterest() override {
        balance *= (1 + 0.05);  // 5% interest rate
        cout << "5% interest rate applied. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if(balance < 500 || balance - amount < 500){
            cout << "Cannot withdraw as current balance is less than $500." << endl;
            return;
        }
        BankAccount :: withdraw(amount);
    }
};

class CurrentAccount : public BankAccount{
public:
    CurrentAccount(string num, double bal) : BankAccount(num, bal) {}
    
    void calculateInterest() override {
        cout << "No interest applied for Current Account." << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < -1000) {
            cout << "Overdraft limit exceeded. Withdrawal denied." << endl;
            return;
        }
        BankAccount :: withdraw(amount);
    }
};

int main(){
    BankAccount *accounts[2];
    accounts[0] = new SavingsAccount("S-1001", 1500.30);
    accounts[1] = new CurrentAccount("C-1002", 890.25);

    accounts[0]->displayDetails();
    accounts[1]->displayDetails();

    cout << endl << "Deposting money into Savings Account:" << endl;
    accounts[0]->deposit(300);
    accounts[0]->deposit(400, "CHK-0687");
    accounts[0]->deposit(200, "Standard Chartered", "908376010");

    cout << endl << "Deposting money into Current Account:" << endl;
    accounts[1]->deposit(100);
    accounts[1]->deposit(200, "CHK-1016");
    accounts[1]->deposit(300, "Meezan Bank", "536782091");

    cout << endl << "Withdrawing money from Savings Account:" << endl;
    accounts[0]->withdraw(600);
    cout << endl << "Withdrawing money from Current Account:" << endl;
    accounts[1]->withdraw(200);

    cout << endl << "Calculating Interest for both accounts:" << endl;
    accounts[0]->calculateInterest();
    accounts[1]->calculateInterest();

    cout << endl << "Total balance in both accounts:";
    BankAccount totalBalance = *accounts[0] + *accounts[1];
    totalBalance.displayDetails();

    cout << endl << "Transferring $200:";
    BankAccount deductedBalance = *accounts[0] - 200;
    deductedBalance.displayDetails();

    cout << endl << "Applying an interest of 5%:";
    BankAccount interestApplied = *accounts[0] * 5;
    interestApplied.displayDetails();

    cout << endl << "Applying installments:";
    BankAccount installmentPayment = *accounts[1] / 4;
    installmentPayment.displayDetails();

    for(int i = 0; i < 2; i++){
        delete accounts[i];
    }

    return 0;
}