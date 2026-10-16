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
#include <limits>
using namespace std;

struct Node
{
    int accountNo;
    string name;
    string accountType;
    double balance;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void addAccount()
{
    Node* newNode = new Node;

    cout << "Enter Account Number: ";
    cin >> newNode->accountNo;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->accountNo == newNode->accountNo)
        {
            cout << "Account number already exists!\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name: ";
    getline(cin, newNode->name);

    cout << "Enter Account Type: ";
    getline(cin, newNode->accountType);

    cout << "Enter Initial Balance: ";
    cin >> newNode->balance;

    if (newNode->balance < 0)
    {
        cout << "Invalid balance!\n";
        delete newNode;
        return;
    }

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Account added successfully!\n";
}

void displayAccounts()
{
    Node* temp = head;

    if (temp == NULL)
    {
        cout << "No accounts available.\n";
        return;
    }

    cout << "\n--- Bank Account Details ---\n";

    while (temp != NULL)
    {
        cout << "\nAccount Number: " << temp->accountNo;
        cout << "\nCustomer Name: " << temp->name;
        cout << "\nAccount Type: " << temp->accountType;
        cout << "\nBalance: " << temp->balance << "\n";

        temp = temp->next;
    }
}

void searchAccount()
{
    int number;
    cout << "Enter Account Number to Search: ";
    cin >> number;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->accountNo == number)
        {
            cout << "Account Found!\n";
            cout << "Name: " << temp->name << "\n";
            cout << "Account Type: " << temp->accountType << "\n";
            cout << "Balance: " << temp->balance << "\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Account not found!\n";
}

void deleteAccount()
{
    int number;
    cout << "Enter Account Number to Delete: ";
    cin >> number;

    Node* temp = head;

    while (temp != NULL && temp->accountNo != number)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Account not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Account deleted successfully!\n";
}

void updateBalance()
{
    int number;
    double amount;

    cout << "Enter Account Number: ";
    cin >> number;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->accountNo == number)
        {
            cout << "Enter New Balance: ";
            cin >> amount;

            if (amount < 0)
            {
                cout << "Invalid balance!\n";
                return;
            }

            temp->balance = amount;
            cout << "Balance updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Account not found!\n";
}

void freeMemory()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT MANAGEMENT =====\n";
        cout << "1. Add Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Update Balance\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                addAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                deleteAccount();
                break;

            case 5:
                updateBalance();
                break;

            case 6:
                freeMemory();
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
    
    
## 7. Conclusion

The Bank Account Management System demonstrates the practical implementation of a doubly linked list in C++. It provides operations for managing account records, updating balances, searching for accounts, deleting records, and traversing the list in both directions. This project improves understanding of pointers, dynamic memory allocation, and linked list operations.

