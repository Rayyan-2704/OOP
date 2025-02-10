#include <iostream>
#include <iomanip>
using namespace std;

class Bank
{
    string accountNumber;
    string ownerName;
    double balance;

public:
    Bank()
    {
        accountNumber = "";
        ownerName = "";
        balance = 0.0;
    }

    Bank(string accountNumber, string ownerName, double balance)
    {
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    void depositMoney()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "Account details have not been defined yet." << endl;
            return;
        }

        double amount;
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Amount $" << fixed << setprecision(2) << amount << " deposited successfully." << endl;
    }

    void withdrawMoney()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "Account details have not been defined yet." << endl;
            return;
        }

        double amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "The amount entered is greater than the current balance. Cannot withdraw." << endl;
            return;
        }

        balance -= amount;
        cout << "Amount $" << fixed << setprecision(2) << amount << " withdrawn successfully." << endl;
    }

    void displayDetails()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "Account details have not been defined yet." << endl;
            return;
        }

        cout << endl << "Displaying account details below" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Owner Name: " << ownerName << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

int main()
{
    Bank b1;
    int choice;

    cout << "----- Bank Account System -----" << endl;
    cout << "Enter 1 to add account details" << endl;
    cout << "Enter 2 to deposit money" << endl;
    cout << "Enter 3 to withdraw money" << endl;
    cout << "Enter 4 to display details" << endl;
    cout << "Enter 5 to exit" << endl;

    while (1)
    {
        cout << endl
             << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {   
            string accNum, name;
            double balance; 
            cin.ignore();
            cout << "Enter the account number: ";
            getline(cin, accNum);
            cout << "Enter the account owner's name: ";
            getline(cin, name);
            cout << "Enter the account balance: ";
            cin >> balance;
            b1 = Bank(accNum, name, balance);
            break;
        }
        case 2:
            b1.depositMoney();
            break;
        case 3:
            b1.withdrawMoney();
            break;
        case 4:
            b1.displayDetails();
            break;
        case 5:
            cout << "Exiting the program...." << endl;
            return 0;
        }
    }
}