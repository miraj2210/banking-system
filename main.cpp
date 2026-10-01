#include <iostream>
#include <string>
using namespace std;

class BankAccount
{

private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int acc, string name, double amount)
    {
        accountNumber = acc;
        accountHolderName = name;
        balance = amount;
    }
    void set_deposit(double amount)
    {
        balance = balance + amount;
    }
    int get_balance()
    {
        return balance;
    }
    virtual void displayAccountInfo()
    {

        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{

private:
    double interestRate;

public:
    SavingsAccount(int acc, string name, double amount, double rate)
        : BankAccount(acc, name, amount)
    {
        interestRate = rate;
    }

    double calculateInterest()
    {
        return get_balance() * interestRate / 100;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int acc, string name, double amount, double limit)
        : BankAccount(acc, name, amount)
    {
        overdraftLimit = limit;
    }

    void checkOverdraft(double withdrawalAmount)
    {
        if (withdrawalAmount <= get_balance() + overdraftLimit)
        {
            cout << "Withdrawal Allowed" << endl;
        }
        else
        {
            cout << "Withdrawal Exceeds Overdraft Limit" << endl;
        }
    }
};
class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount(int acc, string name, double amount, int months)
        : BankAccount(acc, name, amount)
    {
        term;
    }

    double calculateInterest()
    {
        double interestRate = 7.0;
        return get_balance() * interestRate * term / (12 * 100);
    }
};

int main()
{
    int choice;
    double amount;

    SavingsAccount savings(101, "vishal", 1300, 4);

    CheckingAccount checking(102, "sanjay", 3000, 1500);

    FixedDepositAccount fixed(103, "Ajay", 45000, 24);

    do
    {

        cout << " =====BANKING SYSTEM======" << endl;

        cout << "1. Savings Account" << endl;
        cout << "2. Checking Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Check Overdraft" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "===== SAVINGS ACCOUNT =====" << endl;

            savings.displayAccountInfo();

            break;

        case 2:

            cout << "===== CHECKING ACCOUNT =====" << endl;

            checking.displayAccountInfo();

            break;

        case 3:

            cout << "===== FIXED DEPOSIT =====" << endl;

            fixed.displayAccountInfo();

            break;

        case 4:

            cout << "Enter Deposit Amount: ";
            cin >> amount;

            savings.set_deposit(amount);

            cout << "Money Deposited Successfully!" << endl;

            cout << "New Balance: "
                 << savings.get_balance() << endl;

            break;

        case 5:

            cout << "Enter Withdraw Amount: ";
            cin >> amount;

            savings.get_balance();

            cout << "Current Balance: "
                 << savings.get_balance() << endl;

            break;

        case 6:

            cout << "Enter Withdrawal Amount: ";
            cin >> amount;

            checking.checkOverdraft(amount);

            break;

        case 7:

            cout << "Thank You!" << endl;

            break;

        default:

            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}