
## 1. Title
BST and AVL Height Comparison Using C++

## 2. Problem Statement
To develop a C++ program that constructs a Binary Search Tree (BST) and an AVL tree using the same input sequence and compares their heights. The program also counts the number of comparisons required to search for a given key in both trees, tests ascending, descending, and random insertion orders, and displays a summary table of the results. The objective is to understand how balancing affects tree height and search efficiency.

## 3.Objective
1. To understand the construction and working of Binary Search Trees and AVL trees.
2. To compare the heights of BST and AVL trees created using the same input sequence.
3. To implement search operations and count the comparisons required in both trees.
4. To analyze the effect of ascending, descending, and random insertion orders.
5. To display a summary table comparing the height and search efficiency of both trees.

## 4.Algorithm
1. Start the program.
2. Read the number of elements and the input sequence.
3. Create an empty Binary Search Tree and an empty AVL tree.
4. Insert the given elements into the BST using the normal BST insertion method.
5. Insert the same elements into the AVL tree using AVL insertion and rotations to maintain balance.
6. Calculate the height of both trees.
7. Read a search key from the user.
8. Search for the key in the BST and count the number of node comparisons.
9. Search for the same key in the AVL tree and count the number of node comparisons.
10. Repeat the process for ascending, descending, and random insertion orders.
11. Display the height and search comparison counts of both trees in a summary table.
12. Release dynamically allocated memory.
13. Stop the program.
## 5.Flowchart
<img width="854" height="1281" alt="WhatsApp Image 2026-10-13 at 7 40 35 AM" src="https://github.com/user-attachments/assets/723452d5-028e-4d9b-8698-67f21175cda6" />

## 6. program
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node representing a bank account
struct Node {
string name;
int accNo;
string type;
double balance;
Node* next;
Node* prev;
};

// Head pointer refers to the first node
Node* head = nullptr;

// Search for an account by account number
Node* searchAccount(int number) {
Node* temp = head;

```
while (temp != nullptr) {
    if (temp->accNo == number)
        return temp;

    temp = temp->next;
}

return nullptr;
```

}

// Add a new account
void addAccount() {
int number;
string name, type;
double balance;

```
cout << "Enter account number: ";

if (!(cin >> number) || number <= 0) {
    cout << "Invalid account number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

if (searchAccount(number) != nullptr) {
    cout << "Account number already exists.\n";
    return;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Enter account holder name: ";
getline(cin, name);

if (name.empty()) {
    cout << "Name cannot be empty.\n";
    return;
}

cout << "Enter account type: ";
getline(cin, type);

if (type.empty()) {
    cout << "Account type cannot be empty.\n";
    return;
}

cout << "Enter initial balance: ";

if (!(cin >> balance) || balance < 0) {
    cout << "Invalid balance.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* newNode = new Node{
    name, number, type, balance, nullptr, nullptr
};

// Insert at the end of the doubly linked list
if (head == nullptr) {
    head = newNode;
} else {
    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

cout << "Account created successfully.\n";
```

}

// Display all accounts
void displayAccounts() {
if (head == nullptr) {
cout << "No accounts available.\n";
return;
}

```
Node* temp = head;

cout << "\n--- Bank Account Records ---\n";

while (temp != nullptr) {
    cout << "Account Number: " << temp->accNo << '\n';
    cout << "Holder Name: " << temp->name << '\n';
    cout << "Account Type: " << temp->type << '\n';
    cout << "Balance: " << temp->balance << '\n';
    cout << "----------------------------\n";

    temp = temp->next;
}
```

}

// Search and display an account
void findAccount() {
int number;

```
cout << "Enter account number to search: ";

if (!(cin >> number)) {
    cout << "Invalid account number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* account = searchAccount(number);

if (account == nullptr) {
    cout << "Account not found.\n";
} else {
    cout << "Account Number: " << account->accNo << '\n';
    cout << "Holder Name: " << account->name << '\n';
    cout << "Account Type: " << account->type << '\n';
    cout << "Balance: " << account->balance << '\n';
}
```

}

// Deposit money into an account
void depositMoney() {
int number;
double amount;

```
cout << "Enter account number: ";

if (!(cin >> number)) {
    cout << "Invalid account number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* account = searchAccount(number);

if (account == nullptr) {
    cout << "Account not found.\n";
    return;
}

cout << "Enter deposit amount: ";

if (!(cin >> amount) || amount <= 0) {
    cout << "Deposit amount must be positive.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

account->balance += amount;

cout << "Deposit successful. New balance: "
     << account->balance << '\n';
```

}

// Withdraw money from an account
void withdrawMoney() {
int number;
double amount;

```
cout << "Enter account number: ";

if (!(cin >> number)) {
    cout << "Invalid account number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* account = searchAccount(number);

if (account == nullptr) {
    cout << "Account not found.\n";
    return;
}

cout << "Enter withdrawal amount: ";

if (!(cin >> amount) || amount <= 0) {
    cout << "Withdrawal amount must be positive.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

if (amount > account->balance) {
    cout << "Insufficient balance.\n";
    return;
}

account->balance -= amount;

cout << "Withdrawal successful. New balance: "
     << account->balance << '\n';
```

}

// Delete an account
void deleteAccount() {
int number;

```
cout << "Enter account number to delete: ";

if (!(cin >> number)) {
    cout << "Invalid account number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* temp = searchAccount(number);

if (temp == nullptr) {
    cout << "Account not found.\n";
    return;
}

// Update previous node or head
if (temp->prev != nullptr)
    temp->prev->next = temp->next;
else
    head = temp->next;

// Update next node's previous pointer
if (temp->next != nullptr)
    temp->next->prev = temp->prev;

delete temp;

cout << "Account deleted successfully.\n";
```

}

// Free allocated memory
void freeList() {
while (head != nullptr) {
Node* temp = head;
head = head->next;
delete temp;
}
}

int main() {
int choice;

```
do {
    cout << "\n=== Bank Account Management System ===\n";
    cout << "1. Add Account\n";
    cout << "2. Display Accounts\n";
    cout << "3. Search Account\n";
    cout << "4. Deposit Money\n";
    cout << "5. Withdraw Money\n";
    cout << "6. Delete Account\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid menu choice.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    switch (choice) {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            findAccount();
            break;
        case 4:
            depositMoney();
            break;
        case 5:
            withdrawMoney();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
    }

} while (choice != 7);

freeList();
return 0;
```

}

## 7. Output
<img width="706" height="392" alt="image" src="https://github.com/user-attachments/assets/3db2da6f-16c1-4adf-9bdb-bc138961729d" />

## 8. conclusion
The project demonstrates the construction and comparison of Binary Search Trees and AVL trees using C++. It shows how insertion order affects the height of a BST and how AVL rotations maintain a balanced tree. By counting search comparisons and testing ascending, descending, and random insertion orders, the program helps evaluate the effect of tree balancing on search efficiency. Thus, AVL trees provide more predictable search performance than an ordinary BST, particularly when the BST becomes highly unbalanced.
