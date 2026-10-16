## Bank Account Management System Using Stack and Queue with Dynamic Implementation

## problem statement
To develop a Bank Account Management System using dynamically implemented stack and queue data structures in C++. The stack maintains account transaction records, while the queue manages account requests in FIFO order. The system performs insertion, deletion, and display operations using dynamic memory allocation.

## objective
1. To implement stack and queue using dynamic memory allocation.
2. To perform push, pop, enqueue, and dequeue operations.
3. To understand the LIFO principle of stack and the FIFO principle of queue.
4. To manage bank transaction records and account requests efficiently.
5. To use linked lists for dynamic storage without fixed-size arrays.
6. To understand the practical applications of stack and queue in banking operations.

## Approch
1. Define a node structure to store the account number, customer name, transaction amount, and next pointer.
2. Implement a stack using a linked list to store bank transaction records.
3. Use the push operation to add transactions and the pop operation to remove the latest transaction.
4. Implement a queue using a linked list to manage account requests.
5. Use the enqueue operation to add requests and the dequeue operation to process them in order.
6. Provide display functions to show the records stored in the stack and queue.

## Time complexity
1. Stack Push: O(1)
2. Stack Pop: O(1)
3. Display Stack: O(n)
4. Queue Enqueue: O(1)
5. Queue Dequeue: O(1)
6. Display Queue: O(n)

## conclusion 
The Bank Account Management System was implemented using stack and queue with dynamic memory allocation in C++. The stack follows the LIFO principle, while the queue follows the FIFO principle. The program demonstrates insertion, deletion, and display operations using linked lists. This implementation helps in understanding dynamic data structures and their practical applications in managing bank transaction records and account requests efficiently.
Here, n represents the number of nodes in the stack or queue.
8. Use dynamic memory allocation to create nodes as required and release memory after use.

