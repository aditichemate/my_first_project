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