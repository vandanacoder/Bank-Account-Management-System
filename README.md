# Bank Account Management System

## Overview
The Bank Account Management System is a simple console-based application implemented in C++. It allows users to perform basic banking operations including opening a new account, adding cash, withdrawing cash, and checking account balances. The system stores account information in a text file for persistence.

## Features
- **Open New Account**: Create a new bank account by providing an account number and a strong password.
- **Add Cash**: Deposit cash into an existing account by specifying the account number and the amount to deposit.
- **Withdraw Cash**: Withdraw cash from an existing account, ensuring the withdrawal amount does not exceed the available balance.
- **Check Balance**: Display the current balance of an account after verifying the account number and password.

## Setup Instructions

### Prerequisites
- C++ compiler (e.g., g++, clang++)
- Basic command-line knowledge

### Compilation

#### Using Makefile
1. Ensure the `Makefile` is present in your project directory.
2. Open a terminal and navigate to the project directory.
3. Run the following command to compile the application:
   'make'
- This will generate the executable file BankSystem.
   
#### Using CMake
1. Ensure 'CMakeLists.txt' is present in your project directory.
2. Create a build directory and navigate to 
   'mkdir build'
   'cd build'
3. Generate the build files using CMake:
   'cmake ..'
4. Build the project:
   'cmake --build .'
This will generate the executable file BankSystem in the build directory.

#### Running the Application
1. Navigate to the directory containing the executable ('BankSystem').
2. Run the application with:
  './BankSystem'
   
## File Structure
- *main.cpp*: Contains the main functionality of the Bank Account Management System, including user interface and file handling.
- *Account.txt*: Stores account details. Each line represents an account with the format: 'AccountNo : Password : Balance'.
- *Account_Temp.txt*: Temporary file used for updating account details during transactions.
- *INSTRUCTIONS.txt*: Instructions for setting up and using the Bank Account Management System.
- *.gitignore*: Specifies files and directories to be ignored by Git.
  
## Notes
- Ensure 'Account.txt' is accessible and has write permissions. The application will create this file if it doesn’t exist.
- The system uses basic file operations for data handling and does not implement advanced security features such as encryption or database management.
- Handle passwords and sensitive information with care.

## Troubleshooting
- *File Access Issues*: Ensure that the 'Account.txt' file is in the same directory as the executable and has appropriate read/write permissions.
- *Compilation Errors*: Ensure that all dependencies are correctly installed and that you are using a compatible C++ compiler.
  
## Contributors
Vandana: Project Creator and Developer

## License
This project is licensed under the MIT License.
