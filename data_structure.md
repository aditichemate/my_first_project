Data Structure: Doubly Linked List

A doubly linked list is a linear data structure in which each node contains data and two pointers.

Each node contains:

- Name: Account holder's name.
- Account Number: Unique identification number.
- Account Type: Type of bank account.
- Balance: Available account balance.
- Next Pointer: Points to the next node.
- Previous Pointer: Points to the previous node.

Structure

"NULL <- [Account 1] <-> [Account 2] <-> [Account 3] -> NULL"

Why is it used?

1. It allows dynamic storage of account records.
2. It supports insertion and deletion of nodes.
3. It allows forward and backward traversal.
4. It does not require a fixed-size array.
5. It makes searching and managing account records convenient.

Time Complexity:

- Insertion at the end: O(1) when a tail pointer is maintained.
- Searching for an account: O(n).
- Displaying all accounts: O(n).
- Deleting an account after searching: O(n) overall.
