#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <string>
using namespace std;

// Class representing a bank account
class Account 
{
private:
    string AccountNo;  // Account number
    string Password;   // Account password
    int Balance;       // Account balance

public:
    // Default constructor initializing member variables
    Account() : AccountNo(""), Password(""), Balance(0) {}

    // Setter for AccountNo
    void setAccountNo(const string& id) 
    {
        AccountNo = id;
    }

    // Setter for Password
    void setPassword(const string& pw) 
    {
        Password = pw;
    }

    // Setter for Balance
    void setBalance(int balance) 
    {
        Balance = balance;
    }

    // Getter for AccountNo
    string getAccountNo() const 
    {
        return AccountNo;
    }

    // Getter for Password
    string getPassword() const 
    {
        return Password;
    }

    // Getter for Balance
    int getBalance() const 
    {
        return Balance;
    }
};

// Function to open a new account
void openAccount() 
{
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter A Strong Password: ";
    cin >> pw;

    Account user;
    user.setAccountNo(id);
    user.setPassword(pw);
    user.setBalance(0);

    // Open file to save account details
    ofstream outfile("Account.txt", ios::app);
    if (!outfile) 
    {
        cerr << "\tError: File Can't Open!" << endl;
        return;
    }
    // Write account details to file
    outfile << user.getAccountNo() << " : " << user.getPassword() << " : " << user.getBalance() << endl;
    cout << "\tAccount Created Successfully!" << endl;
    Sleep(5000);
}

// Function to add cash to an existing account
void addCash() 
{
    string id;
    cout << "\tEnter Account No: ";
    cin >> id;

    ifstream infile("Account.txt");
    ofstream outfile("Account_Temp.txt");
    if (!infile || !outfile) 
    {
        cout<< "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) 
    {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID) 
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;

            if (cash > 0) 
            { // Ensure positive cash value
                int newBalance = userBalance + cash;
                outfile << userID << " : " << userPW << " : " << newBalance << endl;
                cout << "\tNew Balance Is: " << newBalance << endl;
            } 
            else 
            {
                cout << "\tInvalid Cash Amount!" << endl;
                outfile << line << endl; // Keep old line if cash is invalid
            }
        } 
        else 
        {
            outfile << line << endl; // Write unchanged lines to temp file
        }
    }
    if (!found) 
    {
        cout << "\tInvalid Account No!" << endl;
    }

    infile.close();
    outfile.close();
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");
    Sleep(5000);
}

// Function to withdraw cash from an existing account
void withdraw() 
{
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("Account.txt");
    ofstream outfile("Account_Temp.txt");
    if (!infile || !outfile) 
    {
        cerr << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) 
    {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;

        if (id == userID && pw == userPW) 
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;

            if (cash > 0 && cash <= userBalance) 
            { // Ensure valid withdrawal
                int newBalance = userBalance - cash;
                outfile << userID << " : " << userPW << " : " << newBalance << endl;
                cout << "\tTransaction Was Successful!" << endl;
                cout << "\tRemaining Balance: " << newBalance << endl;
            } 
            else if (cash > userBalance) 
            {
                cout << "\tInsufficient Funds!" << endl;
                outfile << line << endl; // Write unchanged line if insufficient funds
            } 
            else 
            {
                cout << "\tInvalid Cash Amount!" << endl;
                outfile << line << endl; // Write unchanged line if invalid amount
            }
        } 
        else 
        {
            outfile << line << endl; // Write unchanged lines to temp file
        }
    }
    if (!found) 
    {
        cout << "\tInvalid Account No or Password!" << endl;
    }

    infile.close();
    outfile.close();
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");
    Sleep(5000);
}

// Function to check balance of an existing account
void checkBalance() 
{
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("Account.txt");
    if (!infile) 
    {
        cerr << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) 
    {
        stringstream ss(line);
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;

        if (id == userID && pw == userPW) 
        {
            found = true;
            cout << "\tYour Balance is: " << userBalance << endl;
            break;
        }
    }
    if (!found) 
    {
        cout << "\tInvalid Account No or Password!" << endl;
    }

    infile.close();
    Sleep(5000);
}

// Main function to run the bank account management system
int main() 
{
    bool exit = false;
    while (!exit) 
    {
        int val;
        cout << "\tWelcome To Bank Account Management System" << endl;
        cout << "\t*****************************************" << endl;
        cout << "\t-----------------Main Menu---------------" << endl;
        cout << "\t1. Open New Account." << endl;
        cout << "\t2. Add Cash." << endl;
        cout << "\t3. Withdraw Cash." << endl;
        cout << "\t4. Check Balance." << endl;
        cout << "\t5. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        switch (val) 
        {
            case 1:
                openAccount();
                break;
            case 2:
                addCash();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                exit = true;
                cout << "\tGoodbye!" << endl;
                break;
            default:
                cout << "\tInvalid Choice! Please try again." << endl;
                break;
            Sleep(2000); // Pause for user to see message before clearing screen
        }
        Sleep(3000); // Pause for user to read output
    }
    return 0;
}