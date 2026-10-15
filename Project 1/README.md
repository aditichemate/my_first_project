# Bank Account Management System Using Doubly Linked List

## 1. Title

Bank Account Management System Using Doubly Linked List in C++.

## 2. Problem Statement

To develop a Bank Account Management System using a doubly linked list that allows users to create and delete accounts, deposit and withdraw money, check account balances, and display account records in forward and reverse order.

## 3. Objectives

* To understand the implementation of a doubly linked list.
* To store bank account details dynamically.
* To perform insertion and deletion of account records.
* To implement searching using account numbers.
* To perform deposit and withdrawal operations.
* To display account records in forward and reverse order.
* To understand pointers and dynamic memory allocation in C++.

## 4. Algorithm
1. Start the program.
2. Define a node containing account details and two pointers: next and prev.
3. Initialize the head and tail pointers to NULL.
4. Display the main menu.
5. Accept the user's choice.
6. If the choice is 1, create a new bank account and insert it into the list.
7. If the choice is 2, search for an account and deposit money.
8. If the choice is 3, search for an account and withdraw money after checking the balance.
9. If the choice is 4, search for an account and display its balance.
10. If the choice is 5, search for an account and delete it from the list.
11. If the choice is 6, display all accounts from beginning to end.
12. If the choice is 7, display all accounts from end to beginning.
13. If the choice is 8, exit the program.
14. Repeat the menu until the user chooses Exit.
15. Stop the program.

## 5. Flowchart
<img width="1312" height="1199" alt="WhatsApp Image 2026-10-10 at 9 22 23 PM" src="https://github.com/user-attachments/assets/2e5dda47-eef9-43e2-85fb-d0868ce31b43" />

## 6. Program
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Node {
    string name;
    int accNo;
    string type;
    double balance;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

// Search account by account number
Node* searchAccount(int no) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->accNo == no)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Create a new account
void createAccount() {
    Node* n = new Node;

    cout << "Enter Account Holder Name: ";
    cin >> ws;
    getline(cin, n->name);

    cout << "Enter Account Number: ";
    cin >> n->accNo;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account number!\n";
        delete n;
        return;
    }

    if (searchAccount(n->accNo) != NULL) {
        cout << "Account number already exists!\n";
        delete n;
        return;
    }

    cout << "Enter Account Type: ";
    cin >> ws;
    getline(cin, n->type);

    cout << "Enter Initial Balance: ";
    cin >> n->balance;

    if (cin.fail() || n->balance < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid balance!\n";
        delete n;
        return;
    }

    n->next = NULL;
    n->prev = tail;

    if (head == NULL) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }

    cout << "Account created successfully!\n";
}

// Deposit money
void depositMoney() {
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account number!\n";
        return;
    }

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Deposit Amount: ";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid amount!\n";
        return;
    }

    temp->balance += amount;

    cout << fixed << setprecision(2);
    cout << "Deposit successful!\n";
    cout << "Updated Balance: " << temp->balance << "\n";
}

// Withdraw money
void withdrawMoney() {
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account number!\n";
        return;
    }

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Withdrawal Amount: ";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid amount!\n";
        return;
    }

    if (amount > temp->balance) {
        cout << "Insufficient balance!\n";
        return;
    }

    temp->balance -= amount;

    cout << fixed << setprecision(2);
    cout << "Withdrawal successful!\n";
    cout << "Remaining Balance: " << temp->balance << "\n";
}

// Display all accounts in forward direction
void displayAccounts() {
    if (head == NULL) {
        cout << "No accounts available!\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== BANK ACCOUNTS ==========\n";
    cout << fixed << setprecision(2);

    while (temp != NULL) {
        cout << "\nAccount Holder: " << temp->name;
        cout << "\nAccount Number: " << temp->accNo;
        cout << "\nAccount Type: " << temp->type;
        cout << "\nBalance: " << temp->balance;
        cout << "\n-----------------------------------\n";

        temp = temp->next;
    }
}

// Search and display one account
void displaySingleAccount() {
    int no;

    cout << "Enter Account Number to Search: ";
    cin >> no;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account number!\n";
        return;
    }

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nAccount Found!\n";
    cout << "Account Holder: " << temp->name << "\n";
    cout << "Account Number: " << temp->accNo << "\n";
    cout << "Account Type: " << temp->type << "\n";
    cout << "Balance: " << temp->balance << "\n";
}

// Delete an account
void deleteAccount() {
    int no;

    cout << "Enter Account Number to Delete: ";
    cin >> no;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account number!\n";
        return;
    }

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    // If the node is the first node
    if (temp == head) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    // If the node is the last node
    if (temp == tail) {
        tail = temp->prev;
    } else {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Account deleted successfully!\n";
}

// Display accounts in reverse direction
void displayReverse() {
    if (tail == NULL) {
        cout << "No accounts available!\n";
        return;
    }

    Node* temp = tail;

    cout << "\n===== ACCOUNTS IN REVERSE ORDER =====\n";

    while (temp != NULL) {
        cout << "\nAccount Holder: " << temp->name;
        cout << "\nAccount Number: " << temp->accNo;
        cout << "\nBalance: " << fixed << setprecision(2)
             << temp->balance;
        cout << "\n-------------------------------------\n";

        temp = temp->prev;
    }
}

// Free allocated memory
void clearAccounts() {
    Node* temp = head;

    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Search Account\n";
        cout << "6. Delete Account\n";
        cout << "7. Display Accounts in Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter Your Choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                displayAccounts();
                break;

            case 5:
                displaySingleAccount();
                break;

            case 6:
                deleteAccount();
                break;

            case 7:
                displayReverse();
                break;

            case 8:
                clearAccounts();
                cout << "Thank you for using the Bank Management System!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
## 7. Conclusion

The Bank Account Management System demonstrates the practical implementation of a doubly linked list in C++. It provides operations for managing account records, updating balances, searching for accounts, deleting records, and traversing the list in both directions. This project improves understanding of pointers, dynamic memory allocation, and linked list operations.

