#include <iostream>
#include <vector>
#include <string>

class BankAccount
{
};

int main()
{

    std::vector<BankAccount> accounts;
    // Step 2: Display Menu Options
    std::cout << "<======= Banking System ==========>" << std::endl;
    std::cout << "1. Create Account" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Display Account details" << std::endl;
    std::cout << "5. Exit" << std::endl;

    // Step 3: Take User Input for Choice
    int userInput;
    std::cout << "Enter Input:";
    std::cin >> userInput;

    // Step 4: Perform Actions Based on Choice
    switch (userInput)
    {
    case 1:
        std::cout << "Creating Account ........." << std::endl;
        std::cout << "Enter Account Holder Name:";
        std::string name;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Entered Account Holder Name:" << name << std::endl;
        break;
        // case 2:
        //     break;
        // case 3:
        //     break;
        // case 4:
        //     break;
        // case 5:
        //     break;
        // default:
    }

    return 0;
}