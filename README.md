# 🏦 Bank Account Management System

A console-based bank account management application built in both **C** and **C++**, featuring file-based data storage for account persistence.

---

## 📋 Overview

This project is a terminal application that simulates basic banking operations. Account data is stored in a text file (`Account.txt`), making it persistent across sessions. The C++ version uses Object-Oriented Programming with a dedicated `Account` class, while the C version uses structs and procedural programming.

---

## ✨ Features

- **Open New Account** — Create an account with an account number and password (balance starts at 0)
- **Add Cash** — Deposit money into an existing account by account number
- **Withdraw Cash** — Withdraw money with password verification and insufficient funds check
- **Check Balance** — View current balance with account number and password verification
- **File-Based Storage** — Account data saved in `Account.txt` in the format `AccountNo : Password : Balance`
- **Two Versions** — C version uses structs; C++ version uses OOP with a class (getters/setters)

---

## 🛠️ Built With

- C (using `stdio.h`, `stdlib.h`, `string.h`, `windows.h`)
- C++ (using `iostream`, `fstream`, `sstream`, `windows.h`)

> ⚠️ **Note:** This project uses `windows.h` so it is designed to run on **Windows only**.

---

## 📁 Project Structure

```
Bank-Account-Management-System/
├── Bank Account Management System.c      # C version
├── Bank-Account_Management-System.CPP    # C++ version
├── Account.txt                           # Stores account data
├── InputOutputExamples/                  # Sample input/output screenshots
├── INSTRUCTIONS.txt                      # Setup instructions
├── CMakeLists.txt                        # CMake build file
├── .gitignore
├── LICENSE
└── README.md
```

---

## 🚀 How to Compile & Run

### C Version
```bash
gcc "Bank Account Management System.c" -o BankSystem
BankSystem.exe
```

### C++ Version
```bash
g++ "Bank-Account_Management-System.CPP" -o BankSystem
BankSystem.exe
```

### Using CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .
BankSystem.exe
```

---

## 🎮 How to Use

1. Run the executable
2. Choose an option from the **Main Menu** (1–5)
3. Follow the prompts for your chosen operation
4. Enter `5` to exit

```
Main Menu
---------
1. Open New Account
2. Add Cash
3. Withdraw Cash
4. Check Balance
5. Exit
```

---

## 📂 Data Storage Format

Account data is stored in `Account.txt` as:
```
AccountNo : Password : Balance
```
Example:
```
ACC001 : mypassword123 : 5000
```

> Make sure `Account.txt` is in the same directory as the executable. It will be created automatically when the first account is opened.

---

## 👩‍💻 Author

**Vandana**
- GitHub: [@vandanacoder](https://github.com/vandanacoder)

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
