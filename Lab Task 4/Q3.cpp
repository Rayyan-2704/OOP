/* You are building a bank account management system. Create a class `Account` to manage bank accounts.
Requirements:
1. Attributes:
    --> `accountNumber` (string)
    --> `accountHolderName` (string)
    --> `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
    --> `deposit(double amount)`: Adds the amount to the balance.
    --> `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are available).
    --> `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods. */

#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account()
    {
        accountNumber = " ";
        accountHolderName = " ";
        balance = 0.0;
    }

    Account(string accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
        cout << "The amount $" << fixed << setprecision(2) << amount << " has been deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        if (amount > this->balance)
        {
            cout << "The amount $" << fixed << setprecision(2) << amount << " cannot be withdrawn as it exceeds your current balance." << endl;
            return;
        }

        this->balance -= amount;
        cout << "The amount $" << fixed << setprecision(2) << amount << " has been withdrawn successfully." << endl;
    }

    void checkBalance()
    {
        cout << "Accouunt Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Your current balance is $" << fixed << setprecision(2) << balance << endl << endl;
    }
};

int main()
{
    Account a1, a2, a3, a4;

    a1 = Account("247-0687", "Rayyan Aamir", 89.67);
    a1.checkBalance();
    a1.deposit(20.56);
    a1.withdraw(300);
    a1.withdraw(10.20);
    a1.checkBalance();

    a2 = Account("345-7890", "Murtaza Hunaid", 261.90);
    a2.checkBalance();
    a2.withdraw(61.90);
    a2.deposit(100.00);
    a2.withdraw(50.47);
    a2.checkBalance();

    a3 = Account("123-2010", "Yves Saint Laurent", 1800.70);
    a3.checkBalance();
    a3.deposit(34.23);
    a3.deposit(79.81);
    a3.withdraw(41.60);
    a3.checkBalance();

    a4.checkBalance();
    return 0;
}
