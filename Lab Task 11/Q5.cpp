#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception
{
    double deficit;
    string message;

public:
    InsufficientFundsException(const double d) : deficit(d)
    {
        message = "InsufficientFundsException - Deficit: $" + to_string(deficit);
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <class T>
class BankAccount
{
    string ID;
    T balance;

public:
    BankAccount(string id, T bal) : ID(id), balance(bal) {}

    void displayBalance() const
    {
        cout << "Balance for Account ID(" << ID << "): $" << balance << endl;
    }

    T getBalance() const { return balance; }

    void withdraw(T amount)
    {
        if (amount > balance)
        {
            throw InsufficientFundsException(amount - balance);
        }

        balance -= amount;
        cout << "withdrawn $" << amount << " successfully!. New Balance: $" << balance << endl;
    }
};

int main()
{
    BankAccount b("24K-0687", 500.00);
    b.displayBalance();

    try
    {
        // cout << "Withdraw $100: ";
        // b.withdraw(100);
        cout << "Withdraw $600: ";
        b.withdraw(600);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}