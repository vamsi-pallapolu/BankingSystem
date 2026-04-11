#include <iostream>
#include <vector>
#include <string>

class Account
{
private:
    std::string _name;
    long _balance;
    long _accountNumber = 0;
    static long _lastAccountNumber;

public:
    Account(std::string name, long initialBalance) : _name{name}, _balance{initialBalance}
    {
        _accountNumber++;
        _lastAccountNumber = _accountNumber;
    }

    long getAccountNumber()
    {
        return _accountNumber;
    }

    long getBalance()
    {
        return _balance;
    }

    std::string getName()
    {
        return _name;
    }

    void setBalance(long balance)
    {
        _balance = balance;
    }
};

long Account::_lastAccountNumber = 0;

class Bank
{
private:
    std::vector<Account *> accounts;

public:
    void openAccount(const std::string &, long);
    bool isValidAccountNumber(int);
    void checkBalance(long accountNumber);
    void depositMoney(int, long);
    long withDraw(int, long);
    void showAllAccounts();
    void closeAccount(int);
};

void Bank::closeAccount(int accountNumber)
{
    for (const auto account : accounts)
    {
        if (account->getAccountNumber() == accountNumber)
        {
            
        }
    }
}

void Bank::showAllAccounts()
{
    for (const auto account : accounts)
    {
        std::cout << "Account Holder:" << account->getName() << std::endl;
        std::cout << "Balance:" << account->getBalance() << std::endl;
        std::cout << "Account Number:" << account->getAccountNumber() << std::endl;
    }
}

bool Bank::isValidAccountNumber(int accountNumber)
{
    for (const auto account : accounts)
    {
        if (account->getAccountNumber() == accountNumber)
            return true;
    }
    return false;
}

long Bank::withDraw(int accountNumber, long amount)
{
    for (const auto account : accounts)
    {
        if (account->getAccountNumber() == accountNumber)
        {
            if (account->getBalance() - amount > 0)
            {
                account->setBalance(account->getBalance() - amount);
                return account->getBalance();
            }
            else
            {
                std::cout << "Insufficient funds" << std::endl;
            }
        }
    }
    return -1;
}

void Bank::depositMoney(int accountNumber, long amount)
{
    for (const auto account : accounts)
    {
        if (account->getAccountNumber() == accountNumber)
        {
            account->setBalance(account->getBalance() + amount);
            std::cout << "\nBalance Updated\n"
                      << std::endl;
        }
    }
}

void Bank::checkBalance(long acccountNumber)
{
    for (const auto account : accounts)
    {
        if (account->getAccountNumber() == acccountNumber)
        {
            std::cout << "Balance:" << account->getBalance() << std::endl;
            return;
        }
    }
    std::cout << "\nNo account found\n"
              << std::endl;
}

void Bank::openAccount(const std::string &name, long balance)
{
    accounts.push_back(new Account(name, balance));
}

int main()
{

    Bank b;

    int userInput;

    do
    {
        std::cout << "<======= Banking System ==========>" << std::endl;
        std::cout << "1. Open an  Account" << std::endl;
        std::cout << "2. Check Balance" << std::endl;
        std::cout << "3. Deposit Money" << std::endl;
        std::cout << "4. Withdraw Money" << std::endl;
        std::cout << "5. Close an Account" << std::endl;
        std::cout << "6. Display All Account details" << std::endl;
        std::cout << "7. Exit" << std::endl;

        std::cout << "Enter Input:";
        std::cin >> userInput;

        switch (userInput)
        {
        case 1:
        {
            std::cout << "Creating Account ........." << std::endl;
            std::cout << "Enter Account Holder Name:";
            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Entered Account Holder Name:" << name << std::endl;
            std::cout << "Enter initial balance:";
            long initialBalance;
            std::cin >> initialBalance;
            b.openAccount(name, initialBalance);
            break;
        }
        case 2:
        {
            std::cout << "Enter Account Number:";
            int accountNumber;
            std::cin >> accountNumber;
            b.checkBalance(accountNumber);
            break;
        }
        case 3:
        {
            std::cout << "Enter Account Number:";
            int accountNumber;
            std::cin >> accountNumber;
            std::cout << "Enter amount:";
            long amount;
            std::cin >> amount;
            b.depositMoney(accountNumber, amount);
            break;
        }
        case 4:
        {
            std::cout << "Enter Account Number:";
            int accountNumber;
            std::cin >> accountNumber;
            std::cout << "Enter amount:";
            long amount;
            std::cin >> amount;
            b.withDraw(accountNumber, amount);
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            b.showAllAccounts();
            break;
        }
        case 7:
        {
            break;
        }
        }
    } while (userInput != 7);

    return 0;
}