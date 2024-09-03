#include <iostream>
using namespace std;

class SavingAccount {
private:
    char name[50];
    char address[100];
    int accountNo;
    double balance;

public:
    void getdata() {
        cout << "Enter the details of a customer:\n";
        cout << "Name: ";
        cin >> name;
        cout << "\nAddress: ";
        cin >> address;
        cout << "\nAccount number: ";
        cin >> accountNo;
        cout << "\nInitial balance: ";
        cin >> balance;
    }

    void display() {
        cout << "\nThe details of the customer are as follows:\n";
        cout << "Name: " << name;
        cout << "\nAddress: " << address;
        cout << "\nAccount number: " << accountNo;
        cout << "\nBalance: " << balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void showBalance() {
        cout << "Account balance: " << balance << endl;
    }
};

int main() {
    SavingAccount *ps;
    SavingAccount s;
    ps = &s;
    ps->getdata();
    ps->display();

    int choice;
    double amount;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Deposit money" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Show balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                ps->deposit(amount);
                break;
            case 2:
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                ps->withdraw(amount);
                break;
            case 3:
                ps->showBalance();
                break;
            case 4:
                cout << "Exiting the banking system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}