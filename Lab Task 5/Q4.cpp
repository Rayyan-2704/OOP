#include <iostream>
using namespace std;

class BankAccount
{
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}
    BankAccount(string accNum, string accName, double b) : accountNumber(accNum), accountHolderName(accName), balance(b) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << endl <<"Amount $" << amount << " has been deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Amount $" << amount << " cannot be withdrawn as it exceeds the account balance." << endl;
            return;
        }

        balance -= amount;
        cout << endl << "Amount $" << amount << " has been withdrawn successfully." << endl;
    }

    void display()
    {
        cout << endl << "Displaying account details:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount accounts[3] = {BankAccount("24K-0687", "Rayyan Aamir", 2500.99), BankAccount("24K-0832", "Usaid Khan", 1800.75), BankAccount("24K-0634", "Hammad Haider", 2000.30)};

    for (int i = 0; i < 3; i++)
    {
        cout << endl << "-------- Inital Details --------" << endl;
        accounts[i].display();

        accounts[i].deposit(500);
        cout << endl << "-------- Details after deposit --------" << endl;
        accounts[i].display();

        accounts[i].withdraw(200);
        cout << endl << "-------- Details after withdrawal --------" << endl;
        accounts[i].display();
    }
    return 0;
}