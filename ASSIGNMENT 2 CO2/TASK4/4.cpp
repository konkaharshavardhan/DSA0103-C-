#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    string transactions[10];
    int count;
    int nextIndex;

    // Convert amount into string
    string convertAmount(double amount)
    {
        stringstream ss;
        ss << amount;
        return ss.str();
    }

public:

    SavingsAccount(int acc, double initialBalance)
    {
        accountNumber = acc;
        balance = initialBalance;
        count = 0;
        nextIndex = 0;
    }

    // Deposit function
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount" << endl;
            return;
        }

        balance = balance + amount;

        transactions[nextIndex] =
            "Deposited: Rs." + convertAmount(amount);

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
        {
            count++;
        }
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
        {
            cout << "Invalid withdrawal" << endl;
            return;
        }

        balance = balance - amount;

        transactions[nextIndex] =
            "Withdrawn: Rs." + convertAmount(amount);

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
        {
            count++;
        }
    }

    // Display account balance
    void displayBalance()
    {
        cout << "Account Number: "
             << accountNumber << endl;

        cout << "Current Balance: Rs."
             << balance << endl;
    }

    // Display mini statement
    void miniStatement()
    {
        cout << "\nLast Transactions:" << endl;

        int start;

        if (count == 10)
            start = nextIndex;
        else
            start = 0;

        for (int i = 0; i < count; i++)
        {
            int index = (start + i) % 10;

            cout << transactions[index] << endl;
        }
    }
};

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.displayBalance();

    account.miniStatement();

    return 0;
}
