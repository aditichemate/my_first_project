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

#include<iostream>

#include<string>

#include<limits>

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

while (temp != NULL)
{

    if (temp->accNo == no)
        return temp;

    temp = temp->next;
}

return NULL;

}

void addAccount() 
{

int no;

string name, type;

double balance;

cout << "Enter Account Number: ";


cin >> no;

if (searchAccount(no) != NULL)
{

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
}

else {

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

cout << " ";

while (temp != NULL) {

    cout << "Name: " << temp->name
         << "\nAccount Number: " << temp->accNo
         << "\nAccount Type: " << temp->type
         << "\nBalance: " << temp->balance
         << "\n-------------------------\n";

    temp = temp->next;
}

}

void displayBackward() 

{

if (tail == NULL) {

cout << "No accounts available.\n";

return;

}

Node* temp = tail;

cout << " ";

while (temp != NULL)
{

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

if (temp == NULL)
{

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

if (!(cin >> amount) || amount <= 0) 
{

    cout << "Invalid deposit amount!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

temp->balance += amount;

cout << "Deposit successful!\n";

cout << "Updated Balance: " << temp->balance << "\n";

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

    cout << "Account not found!\n";
    return;
}

cout << "Enter Withdrawal Amount: ";

if (!(cin >> amount) || amount <= 0)

{
    cout << "Invalid withdrawal amount!\n";
    
    cin.clear();
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return;
}

if (amount > temp->balance)
{

    cout << "Insufficient balance!\n";
    
    return;
}

temp->balance -= amount;

cout << "Withdrawal successful!\n";

cout << "Remaining Balance: " << temp->balance << "\n";

}

void deleteAccount()

{

int no;

cout << "Enter Account Number to Delete: ";

cin >> no;

Node* temp = searchAccount(no);

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
else

    tail = temp->prev;

delete temp;

cout << "Account deleted successfully!\n";

}

void freeMemory()
{

Node* temp = head;

while (temp != NULL) 

{

    Node* nextNode = temp->next;
    delete temp;
    temp = nextNode;
}

head = tail = NULL;

}

int main()
{

int choice;

do

{
    cout << " ";
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

} 

while (choice != 8);

return 0;

}

output
<img width="1429" height="682" alt="WhatsApp Image 2026-10-10 at 8 50 09 PM" src="https://github.com/user-attachments/assets/6f9b18d8-86e6-481d-ac37-a47a5837bd09" />

conclusion
The Bank Account Management System was developed using C++ and a doubly linked list. It demonstrates how bank account records can be added, searched, displayed, updated through deposits and withdrawals, and deleted efficiently.
The project provides practical knowledge of pointers, dynamic memory allocation, structures, and linked-list operations. The ability to traverse records in both directions makes the doubly linked list suitable for this application.
Thus, the project helps in understanding the practical use of data structures in record management systems.






