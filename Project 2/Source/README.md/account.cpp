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
