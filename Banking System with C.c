#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10

struct Account {
    int accountNumber;
    char accountHolder[50];
    char accountType[20];
    float accountBalance;
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    struct Account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);

    printf("Enter account type: ");
    scanf("%s", newAccount.accountType);

    printf("Enter initial account balance: ");
    scanf("%f", &newAccount.accountBalance);

    accounts[numAccounts++] = newAccount;

    printf("Account created successfully.\n");
}

void depositAmount() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].accountBalance += amount;
            printf("Deposit successful. Updated balance: %.2f\n", accounts[i].accountBalance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdrawAmount() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].accountBalance >= amount) {
                accounts[i].accountBalance -= amount;
                printf("Withdrawal successful. Updated balance: %.2f\n", accounts[i].accountBalance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2f\n", accounts[i].accountBalance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Banking System ---\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check account balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositAmount();
                break;
            case 3:
                withdrawAmount();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
