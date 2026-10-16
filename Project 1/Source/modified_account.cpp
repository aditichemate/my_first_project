#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int accNo;
    string name;
    double balance;
    Node* next;
};

Node* top = NULL;
Node* front = NULL;
Node* rear = NULL;

Node* createNode()
{
    Node* newNode = new Node;

    cout << "Enter Account Number: ";
    cin >> newNode->accNo;

    cout << "Enter Account Holder Name: ";
    cin >> newNode->name;
cout << "Enter Balance: ";
    cin >> newNode->balance;

    newNode->next = NULL;
    return newNode;
}

// Push operation for Stack
void push()
{
    Node* newNode = createNode();
    newNode->next = top;
    top = newNode;

    cout << "Account pushed into Stack successfully.\n";
}

// Pop operation for Stack
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty.\n";
        return;
    }

    Node* temp = top;

    cout << "Removed Account: " << temp->accNo
         << " - " << temp->name << endl;

    top = top->next;
    delete temp;
}

// Display Stack
void displayStack()
{
    Node* temp = top;

    if (temp == NULL)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "\nStack Account Records:\n";

    while (temp != NULL)
    {
        cout << "Account No: " << temp->accNo
             << ", Name: " << temp->name
             << ", Balance: " << temp->balance << endl;

        temp = temp->next;
    }
}

// Enqueue operation for Queue
void enqueue()
{
    Node* newNode = createNode();

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Account added to Queue successfully.\n";
}

// Dequeue operation for Queue
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;

    cout << "Removed Account: " << temp->accNo
         << " - " << temp->name << endl;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

// Display Queue
void displayQueue()
{
    Node* temp = front;
    if (temp == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "\nQueue Account Records:\n";

    while (temp != NULL)
    {
        cout << "Account No: " << temp->accNo
             << ", Name: " << temp->name
             << ", Balance: " << temp->balance << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Bank Account Management System ---\n";
cout << "1. Push into Stack\n";
        cout << "2. Pop from Stack\n";
        cout << "3. Display Stack\n";
        cout << "4. Enqueue into Queue\n";
        cout << "5. Dequeue from Queue\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                enqueue();
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    while (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;

    return 0;
}

