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

    if (head == NULL) {
        head = tail = n;
    } else {
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
