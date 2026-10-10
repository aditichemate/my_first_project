unit 3- linked lidst project: Bank Account Management System Using Doubly Linked List

Problem Statement
Managing bank account records manually can be difficult and time-consuming. It is necessary to maintain account information such as the account holder's name, account number, account type, and balance.
The Bank Account Management System uses a doubly linked list to store and manage bank account records dynamically. Each node contains account information and two pointers, "next" and "prev", which allow movement in both forward and backward directions.
The system supports adding new accounts, displaying all accounts, searching for an account, depositing money, withdrawing money, and deleting an account.

Objectives
1. To develop a Bank Account Management System using C++.
2. To implement a doubly linked list for storing bank account records.
3. To create new bank accounts dynamically.
4. To search for a bank account using its account number.
5. To deposit money into an existing account.
6. To withdraw money while checking the available balance.
7. To display account details in forward and backward directions.
8. To delete an account when required.
9. To understand dynamic memory allocation and pointer operations.
    
flowchart
<img width="1312" height="1199" alt="WhatsApp Image 2026-10-10 at 9 22 23 PM" src="https://github.com/user-attachments/assets/eb625536-63c3-440e-ab53-bc5cbb70e9da" />

program

#include <iostream>
#include <string>
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

Node* searchAccount(int no) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->accNo == no)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void createAccount() {
    Node* n = new Node;

    cout << "Enter Account Holder Name: ";
    cin >> ws;
    getline(cin, n->name);

    cout << "Enter Account Number: ";
    cin >> n->accNo;

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

    if (n->balance < 0) {
        cout << "Invalid balance!\n";
        delete n;
        return;
    }

    n->next = NULL;
    n->prev = tail;

    if (head == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }

    cout << "Account created successfully!\n";
}

void depositMoney() {
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Deposit Amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    temp->balance += amount;
    cout << "Deposit successful!\n";
    cout << "Balance: " << temp->balance << "\n";
}

void withdrawMoney() {
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Withdrawal Amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    if (amount > temp->balance) {
        cout << "Insufficient balance!\n";
        return;
    }

    temp->balance -= amount;
    cout << "Withdrawal successful!\n";
    cout << "Balance: " << temp->balance << "\n";
}

void checkBalance() {
    int no;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL)
        cout << "Account not found!\n";
    else
        cout << "Account Holder: " << temp->name
             << "\nBalance: " << temp->balance << "\n";
}

void deleteAccount() {
    int no;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL) {
        cout << "Account not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
    cout << "Account deleted successfully!\n";
}

void displayForward() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "No accounts available.\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nName: " << temp->name
             << "\nAccount Number: " << temp->accNo
             << "\nAccount Type: " << temp->type
             << "\nBalance: " << temp->balance << "\n";

        temp = temp->next;
    }
}

void displayReverse() {
    Node* temp = tail;

    if (temp == NULL) {
        cout << "No accounts available.\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nName: " << temp->name
             << "\nAccount Number: " << temp->accNo
             << "\nAccount Type: " << temp->type
             << "\nBalance: " << temp->balance << "\n";

        temp = temp->prev;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- BANK ACCOUNT MANAGEMENT ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Delete Account\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Display Accounts in Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: deleteAccount(); break;
            case 6: displayForward(); break;
            case 7: displayReverse(); break;
            case 8: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    return 0;
}
output
<img width="1429" height="682" alt="WhatsApp Image 2026-10-10 at 8 50 09 PM" src="https://github.com/user-attachments/assets/6f9b18d8-86e6-481d-ac37-a47a5837bd09" />

conclusion
The Bank Account Management System was developed using C++ and a doubly linked list. It demonstrates how bank account records can be added, searched, displayed, updated through deposits and withdrawals, and deleted efficiently.
The project provides practical knowledge of pointers, dynamic memory allocation, structures, and linked-list operations. The ability to traverse records in both directions makes the doubly linked list suitable for this application.
Thus, the project helps in understanding the practical use of data structures in record management systems.






