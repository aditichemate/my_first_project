# Bank Account Management System Using Doubly Linked List

## 1. Title

Bank Account Management System Using Doubly Linked List in C++.

## 2. Project

The Bank Account Management System is a C++ project developed to manage bank account records using a doubly linked list. It allows users to store and manage account information dynamically.

## 3. Operations

1. Add a new bank account.
2. Display all bank accounts.
3. Search for an account using the account number.
4. Deposit money into an account.
5. Withdraw money from an account.
6. Delete a bank account.
7. Exit the program.

## 4. Working

The program uses a menu-driven approach. The user selects an operation from the menu, and the program performs the selected task. Each bank account is stored in a node containing the account number, account holder's name, balance, and two pointers: `prev` and `next`. The `prev` pointer links to the previous node, while the `next` pointer links to the next node. The program continues until the user selects Exit.

## 5. Data Structure

**Doubly Linked List**

A doubly linked list is a linear data structure in which each node contains data and two pointers. It supports traversal in both forward and backward directions and allows dynamic insertion and deletion of nodes.

In this project, each node stores:

* Account number
* Account holder's name
* Account balance
* Previous pointer (`prev`)
* Next pointer (`next`)

## 6. Programming Language

**C++**

C++ is used to implement the project with structures, pointers, functions, dynamic memory allocation, and doubly linked list operations.

