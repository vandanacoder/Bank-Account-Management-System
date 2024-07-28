#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure representing a bank account
typedef struct 
{
    char AccountNo[50];  // Account number
    char Password[50];   // Account password
    int Balance;         // Account balance
} Account;

// Function to open a new account
void openAccount() 
{
    char id[50], pw[50];
    printf("\tEnter Account No: ");
    scanf("%s", id);

    printf("\tEnter A Strong Password: ");
    scanf("%s", pw);

    Account user;
    strcpy(user.AccountNo, id);
    strcpy(user.Password, pw);
    user.Balance = 0;

    // Open file to save account details
    FILE *outfile = fopen("Account.txt", "a");
    if (!outfile) 
    {
        printf("\tError: File Can't Open!\n");
        return;
    }

    // Write account details to file
    fprintf(outfile, "%s : %s : %d\n", user.AccountNo, user.Password, user.Balance);
    printf("\tAccount Created Successfully!\n");
    fclose(outfile);
    Sleep(5000);
}

// Function to add cash to an existing account
void addCash() 
{
    char id[50];
    printf("\tEnter Account No: ");
    scanf("%s", id);

    FILE *infile = fopen("Account.txt", "r");
    FILE *outfile = fopen("Account_Temp.txt", "w");
    if (!infile || !outfile) 
    {
        printf("\tError: File Can't Open!\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), infile)) 
    {
        char userID[50], userPW[50];
        int userBalance;

        sscanf(line, "%s : %s : %d", userID, userPW, &userBalance);
        if (strcmp(id, userID) == 0) 
        {
            found = 1;
            int cash;
            printf("\tEnter Cash: ");
            scanf("%d", &cash);

            if (cash > 0) 
            { // Ensure positive cash value
                int newBalance = userBalance + cash;
                fprintf(outfile, "%s : %s : %d\n", userID, userPW, newBalance);
                printf("\tNew Balance Is: %d\n", newBalance);
            } else 
            {
                printf("\tInvalid Cash Amount!\n");
                fprintf(outfile, "%s", line); // Keep old line if cash is invalid
            }
        } 
        else 
        {
            fprintf(outfile, "%s", line); // Write unchanged lines to temp file
        }
    }
    if (!found) 
    {
        printf("\tInvalid Account No!\n");
    }

    fclose(infile);
    fclose(outfile);
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");
    Sleep(5000);
}

// Function to withdraw cash from an existing account
void withdraw() 
{
    char id[50], pw[50];
    printf("\tEnter Account No: ");
    scanf("%s", id);

    printf("\tEnter Password: ");
    scanf("%s", pw);

    FILE *infile = fopen("Account.txt", "r");
    FILE *outfile = fopen("Account_Temp.txt", "w");
    if (!infile || !outfile) 
    {
        printf("\tError: File Can't Open!\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), infile)) 
    {
        char userID[50], userPW[50];
        int userBalance;

        sscanf(line, "%s : %s : %d", userID, userPW, &userBalance);

        if (strcmp(id, userID) == 0 && strcmp(pw, userPW) == 0) 
        {
            found = 1;
            int cash;
            printf("\tEnter Cash: ");
            scanf("%d", &cash);

            if (cash > 0 && cash <= userBalance) 
            { // Ensure valid withdrawal
                int newBalance = userBalance - cash;
                fprintf(outfile, "%s : %s : %d\n", userID, userPW, newBalance);
                printf("\tTransaction Was Successful!\n");
                printf("\tRemaining Balance: %d\n", newBalance);
            } 
            else if (cash > userBalance) 
            {
                printf("\tInsufficient Funds!\n");
                fprintf(outfile, "%s", line); // Write unchanged line if insufficient funds
            } 
            else 
            {
                printf("\tInvalid Cash Amount!\n");
                fprintf(outfile, "%s", line); // Write unchanged line if invalid amount
            }
        } 
        else 
        {
            fprintf(outfile, "%s", line); // Write unchanged lines to temp file
        }
    }
    if (!found) 
    {
        printf("\tInvalid Account No or Password!\n");
    }

    fclose(infile);
    fclose(outfile);
    remove("Account.txt");
    rename("Account_Temp.txt", "Account.txt");
    Sleep(5000);
}

// Function to check balance of an existing account
void checkBalance() {
    char id[50], pw[50];
    printf("\tEnter Account No: ");
    scanf("%s", id);

    printf("\tEnter Password: ");
    scanf("%s", pw);

    FILE *infile = fopen("Account.txt", "r");
    if (!infile) 
    {
        printf("\tError: File Can't Open!\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), infile)) 
    {
        char userID[50], userPW[50];
        int userBalance;

        sscanf(line, "%s : %s : %d", userID, userPW, &userBalance);

        if (strcmp(id, userID) == 0 && strcmp(pw, userPW) == 0) 
        {
            found = 1;
            printf("\tYour Balance is: %d\n", userBalance);
            break;
        }
    }
    if (!found) 
    {
        printf("\tInvalid Account No or Password!\n");
    }

    fclose(infile);
    Sleep(5000);
}

// Main function to run the bank account management system
int main() 
{
    int exit = 0;
    while (!exit) 
    {
        int val;
        printf("\tWelcome To Bank Account Management System\n");
        printf("\t*****************************************\n");
        printf("\t-----------------Main Menu---------------\n");
        printf("\t1. Open New Account.\n");
        printf("\t2. Add Cash.\n");
        printf("\t3. Withdraw Cash.\n");
        printf("\t4. Check Balance.\n");
        printf("\t5. Exit.\n");
        printf("\tEnter Your Choice: ");
        scanf("%d", &val);

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
                exit = 1;
                printf("\tGoodbye!\n");
                break;
            default:
                printf("\tInvalid Choice! Please try again.\n");
                break;
        }
        Sleep(3000); // Pause for user to read output
    }
    return 0;
}