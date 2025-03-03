/*
Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
• display(): Displays the account details including the account number, account holder name, and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.
*/

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
