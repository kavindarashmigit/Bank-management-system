#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};

// Function to create a new bank account
struct BankAccount createAccount() {
    struct BankAccount newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    newAccount.balance = 0.0;
    printf("Account created successfully!\n");
    return newAccount;
}

// Function to display account details
void displayAccount(struct BankAccount account) {
    printf("\nAccount Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: $%.2f\n", account.balance);
}

// Function to deposit money into an account
void deposit(struct BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! Current balance: $%.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(struct BankAccount *account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds!\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful! Current balance: $%.2f\n", account->balance);
    }
}

int main() {
    struct BankAccount accounts[10];  // Array to store up to 10 accounts
    int numAccounts = 0;  // Variable to keep track of the number of accounts

    int choice;
    do {
        printf("\n1. Create Account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAccounts < 10) {
                    accounts[numAccounts] = createAccount();
                    numAccounts++;
                } else {
                    printf("Maximum number of accounts reached!\n");
                }
                break;
            case 2:
                if (numAccounts > 0) {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);

                    int accountIndex = -1;
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            accountIndex = i;
                            break;
                        }
                    }

                    if (accountIndex != -1) {
                        displayAccount(accounts[accountIndex]);
                    } else {
                        printf("Account not found!\n");
                    }
                } else {
                    printf("No accounts available!\n");
                }
                break;
            case 3:
                if (numAccounts > 0) {
                    int accountNumber;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);

                    int accountIndex = -1;
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            accountIndex = i;
                            break;
                        }
                    }

                    if (accountIndex != -1) {
                        printf("Enter deposit amount: $");
                        scanf("%f", &amount);
                        deposit(&accounts[accountIndex], amount);
                    } else {
                        printf("Account not found!\n");
                    }
                } else {
                    printf("No accounts available!\n");
                }
                break;
            case 4:
                if (numAccounts > 0) {
                    int accountNumber;
                    float amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);

                    int accountIndex = -1;
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accountNumber == accountNumber) {
                            accountIndex = i;
                            break;
                        }
                    }

                    if (accountIndex != -1) {
                        printf("Enter withdrawal amount: $");
                        scanf("%f", &amount);
                        withdraw(&accounts[accountIndex], amount);
                    } else {
                        printf("Account not found!\n");
                    }
                } else {
                    printf("No accounts available!\n");
                }
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
