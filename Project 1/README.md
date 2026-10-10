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

Node* searchAccount(int no)
{
    Node* temp = head;

    while (temp != NULL) {
        if (temp->accNo == no)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void createAccount()
{
    Node* n = new Node;

    cout << "Enter Account Holder Name: ";
    cin >> ws;
    getline(cin, n->name);

    cout << "Enter Account Number: ";
    cin >> n->accNo;

    if (searchAccount(n->accNo) != NULL)
    {
        cout << "Account number already exists!\n";
        delete n;
        return;
    }

    cout << "Enter Account Type: ";
    cin >> ws;
    getline(cin, n->type);

    cout << "Enter Initial Balance: ";
    cin >> n->balance;

    if (n->balance < 0) 
    {
        cout << "Invalid balance!\n";
        delete n;
        return;
    }

    n->next = NULL;
    n->prev = tail;

    if (head == NULL) {
        head = tail = n;
    } 
    else {
        tail->next = n;
        tail = n;
    }

    cout << "Account created successfully!\n";
}

void depositMoney()
{
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL) 
    {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Deposit Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount!\n";
        return;
    }

    temp->balance += amount;

    cout << "Deposit successful!\n";
    cout << "Balance: " << temp->balance << "\n";
}

void withdrawMoney() 
{
    int no;
    double amount;

    cout << "Enter Account Number: ";
    cin >> no;

    Node* temp = searchAccount(no);

    if (temp == NULL) 
    {

## 7. Output

<img width="1429" height="682" alt="WhatsApp Image 2026-10-10 at 8 50 09 PM" src="https://github.com/user-attachments/assets/b88d0f3c-5d26-4144-99d5-9a96bb096baf" />

## 8. Conclusion

The Bank Account Management System demonstrates the practical implementation of a doubly linked list in C++. It provides operations for managing account records, updating balances, searching for accounts, deleting records, and traversing the list in both directions. This project improves understanding of pointers, dynamic memory allocation, and linked list operations.

