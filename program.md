#include <iostream>
#include <string>
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

Node* searchAccount(int no) {
Node* temp = head;

while (temp != NULL) {
    if (temp->accNo == no)
        return temp;

    temp = temp->next;
}

return NULL;

}

void addAccount() {
int no;
string name, type;
double balance;

cout << "Enter Account Number: ";
cin >> no;

if (searchAccount(no) != NULL) {
    cout << "Account number already exists!\n";
    return;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Enter Account Holder Name: ";
getline(cin, name);

cout << "Enter Account Type: ";
getline(cin, type);

cout << "Enter Initial Balance: ";
if (!(cin >> balance) || balance < 0) {
    cout << "Invalid balance!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

Node* newNode = new Node;
newNode->name = name;
newNode->accNo = no;
newNode->type = type;
newNode->balance = balance;
newNode->next = NULL;
newNode->prev = tail;

if (head == NULL) {
    head = tail = newNode;
} else {
    tail->next = newNode;
    tail = newNode;
}

cout << "Account created successfully!\n";

}

void displayForward() {
if (head == NULL) {
cout << "No accounts available.\n";
return;
}

Node* temp = head;

cout << "\n--- Bank Accounts (Forward) ---\n";

while (temp != NULL) {
    cout << "Name: " << temp->name
         << "\nAccount Number: " << temp->accNo
         << "\nAccount Type: " << temp->type
         << "\nBalance: " << temp->balance
         << "\n-------------------------\n";

    temp = temp->next;
}

}

void displayBackward() {
if (tail == NULL) {
cout << "No accounts available.\n";
return;
}

Node* temp = tail;

cout << "\n--- Bank Accounts (Backward) ---\n";

while (temp != NULL) {
    cout << "Name: " << temp->name
         << "\nAccount Number: " << temp->accNo
         << "\nAccount Type: " << temp->type
         << "\nBalance: " << temp->balance
         << "\n-------------------------\n";

    temp = temp->prev;
}

}

void searchAndDisplay() {
int no;

cout << "Enter Account Number to Search: ";
cin >> no;

Node* temp = searchAccount(no);

if (temp == NULL) {
    cout << "Account not found!\n";
    return;
}

cout << "\nAccount Found!\n";
cout << "Name: " << temp->name
     << "\nAccount Number: " << temp->accNo
     << "\nAccount Type: " << temp->type
     << "\nBalance: " << temp->balance << "\n";

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
if (!(cin >> amount) || amount <= 0) {
    cout << "Invalid deposit amount!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

temp->balance += amount;
cout << "Deposit successful!\n";
cout << "Updated Balance: " << temp->balance << "\n";

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
if (!(cin >> amount) || amount <= 0) {
    cout << "Invalid withdrawal amount!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

if (amount > temp->balance) {
    cout << "Insufficient balance!\n";
    return;
}

temp->balance -= amount;

cout << "Withdrawal successful!\n";
cout << "Remaining Balance: " << temp->balance << "\n";

}

void deleteAccount() {
int no;

cout << "Enter Account Number to Delete: ";
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

void freeMemory() {
Node* temp = head;

while (temp != NULL) {
    Node* nextNode = temp->next;
    delete temp;
    temp = nextNode;
}

head = tail = NULL;

}

int main() {
int choice;

do {
    cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Account\n";
    cout << "2. Display Accounts Forward\n";
    cout << "3. Display Accounts Backward\n";
    cout << "4. Search Account\n";
    cout << "5. Deposit Money\n";
    cout << "6. Withdraw Money\n";
    cout << "7. Delete Account\n";
    cout << "8. Exit\n";
    cout << "Enter Your Choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    switch (choice) {
        case 1:
            addAccount();
            break;

        case 2:
            displayForward();
            break;

        case 3:
            displayBackward();
            break;

        case 4:
            searchAndDisplay();
            break;

        case 5:
            depositMoney();
            break;

        case 6:
            withdrawMoney();
            break;

        case 7:
            deleteAccount();
            break;

        case 8:
            freeMemory();
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
    }

} while (choice != 8);

return 0;

}
