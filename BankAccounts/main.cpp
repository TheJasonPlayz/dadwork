#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

class BankAccount
{
private:
    string Name, Type; // Account holder name and account type
    int Num;           // Account number
    double Bal, Int;   // Account balance and interest rate

public:
    BankAccount()
    {
        Name = "";
        Type = "";
        Num = 0;
        Bal = 1000;
        Int = 5;
    }
    /* SETTERS */
    void setName(string name)
    {
        Name = name;
    }
    void setBal(double bal)
    {
        Bal = bal;
    }
    void setInt(double interest)
    {
        Int = interest;
    }
    void setNum(int num)
    {
        Num = num;
    }
    void setType(string type)
    {
        if (type == "C" || type == "c")
        {
            Type = "Checking";
        }
        else if (type == "S" || type == "s")
        {
            Type = "Savings";
        }
        else
        {
            cout << "You have entered a type of account that is not in our system. Please try again.";
            Type = "";
        }
    }
    /* GETTERS */
    string getName()
    {
        return Name;
    }
    string getType()
    {
        return Type;
    }
    int getNumber()
    {
        return Num;
    }
    double getBal()
    {
        return Bal;
    }
    double getInterest()
    {
        return Int;
    }
    /* DISPLAY INFO */
    void display()
    { // Display account details
        cout << "\nThe details of the Account is.." << endl
             << "\nName : " << getName() << endl
             << "\nAccount Number : " << getNumber() << endl
             << "\nAccount Type : " << getType() << endl
             << "\nBalance : "
             << "$" << getBal() << endl
             << "\nInterest Rate : " << getInterest() << "%" << endl;
    }
    /* RANDOM NUMBER */
    int random(int max)
    {
        return rand() % max + 1;
    }
    /* SET USER INPUT */
    void userInput()
    {
        string nameinput, typeinput;
        double balinput;
        cout << "What is your name? (NO SPACES): " << endl;
        cin >> nameinput;
        cout << "What is your account type? : " << endl;
        cin >> typeinput;
        cout << "What is your starting balance? : " << endl;
        cin >> balinput;

        setName(nameinput);
        setType(typeinput);
        setBal(balinput);
    }
    /* DEPOSIT AND WITHDRAWAL */
    void deposit(double val)
    {
        setBal(Bal += val);
        cout << "\nThe new balance is " << getBal() << endl;
    }
    void withdrawal(double val)
    {
        if (val > Bal)
        {
            cout << "\nSorry.. There is no sufficient balance..";
        }
        else
        {
            setBal(Bal -= val);
            cout << "\nThe new balance is " << getBal() << endl;
        }
    }
};

BankAccount createAccount()
{
    BankAccount Account;
    Account.userInput();
    Account.setNum(Account.random(1000));
    Account.setInt(Account.random(10));

    return Account;
}

class AccountManager
{
private:
    BankAccount Accounts[10];
public:
    /* DEFAULT CONSTRUCTOR */
    AccountManager(BankAccount arr[10])
    {
        for (int i = 0; i < 10; i++)
        {
            Accounts[i] = arr[i];
        }
    }
    /* GETTER */
    BankAccount getAccounts() {
        return Accounts;
    }
    /* FIND EMPTY BANK ACCOUNT */
    BankAccount findEmpty()
    {
        BankAccount accounts = getAccounts();
        for (int i = 0; i < 10; i++)
        {
            if (accounts[i].getName() == "")
            {
                BankAccount found = accounts[i];
                return found;
            }
            else {
                BankAccount Placeholder;
                Placeholder.setType("FAIL");
                return Placeholder;
            }

    }
    /* FIND NON-EMPTY BANK ACCOUNTS */
    BankAccount findNotEmpty()
    {
        BankAccount accounts = getAccounts();
        for (int i = 0; i < 10; i++)
        {
            if (accounts[i].getName() != "")
            {
                BankAccount found = accounts[i];
                return found;
            }
            else {
                BankAccount Placeholder;
                Placeholder.setType("FAIL");
                return Placeholder;
            }
        }
    }
};

char mainMenu()
{
    char input;
    cout << "\t\t===== WELCOME TO THE BANK MANAGER APPLICATION =====" << endl
         << "HERE ARE YOUR CHOICES! : " << endl
         << "1. Create a new account!" << endl
         << "2. Display info for an existing account" << endl;
    cin >> input;
    return input;
}

void functions(char choice, AccountManager Manager)
{
    if (choice == '1')
    {
        BankAccount newAccount = createAccount();
        BankAccount empty = Manager.findEmpty();
        empty = newAccount;
    }
    else if (choice == '2')
    {
        BankAccount Existing = Manager.findNotEmpty();
        Existing.display();
    }
    else
    {
        cout << "You have entered a non-menu item. Please try again." << endl;
    }
}

int main()
{
    BankAccount Accounts[10];

    srand(time(NULL));

    while (true)
    {
        char input;
        AccountManager Manager(Accounts);

        input = mainMenu();
        functions(input, Manager);
    }
}