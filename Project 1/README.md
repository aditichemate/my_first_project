## Problem statement
To develop a Bank Account Management System using a doubly linked list in C++. The system stores and manages customer account details and performs operations such as insertion, deletion, searching, updating account balances, and displaying account information using dynamic memory allocation.

## Objective 
1. To implement a doubly linked list for managing bank account records.
2. To perform insertion and deletion of account details.
3. To search for a customer account using the account number.
4. To update and display account information efficiently.
5. To understand dynamic memory allocation in linked lists.
6. To perform forward and backward traversal using previous and next pointers.
7. To manage account records without using fixed-size arrays.

## Approach
1. Define a node structure containing the account number, customer name, account type, balance, and previous and next pointers.
2. Initialize the head pointer to NULL.
3. Create a function to insert new account details into the list.
4. Traverse the list to display all account records.
5. Search for an account using its account number.
6. Delete the required account by updating the previous and next pointers.
7. Update the balance of an existing account.
8. Use dynamic memory allocation to create nodes and release memory when required.

## Time Complexity
1. Insertion at the Beginning: O(1)
2. Insertion at the End: O(n)
3. Deletion of an Account: O(n)
4. Searching for an Account: O(n)
5. Displaying All Accounts: O(n)
6. Updating Account Balance: O(n)

Here, n represents the total number of bank account records in the doubly linked list.

## Conclusion
The Bank Account Management System was successfully implemented using a doubly linked list in C++. The system performs insertion, deletion, searching, updating, and displaying operations on bank account records. Dynamic memory allocation allows the system to manage records as required, while the previous and next pointers support traversal in both directions. This implementation helps in understanding the practical applications of doubly linked lists in data management.
