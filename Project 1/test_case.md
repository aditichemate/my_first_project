## Test Cases

## Test Case 1: Normal Operations

Input:

- Push account: 101, Aditi, Balance: 5000
- Push account: 102, Apurva, Balance: 8000
- Display Stack
- Enqueue account: 103, Akshada, Balance: 6000
- Enqueue account: 104, Vibha, Balance: 7000
- Display Queue

Expected Output:

- Stack displays accounts 102 and 101 in LIFO order.
- Queue displays accounts 103 and 104 in FIFO order.

Result: Pass

## Test Case 2: Empty Stack and Queue

Input:

- Display Stack
- Pop account from Stack
- Display Queue
- Dequeue account from Queue

Expected Output:

- Stack is empty.
- Stack underflow is displayed when attempting to pop.
- Queue is empty.
- Queue underflow is displayed when attempting to dequeue.

Result: Pass

## Test Case 3: Single Account Operation

Input:

- Push account: 105, Rahul, Balance: 3000
- Display Stack
- Pop account
- Display Stack
- Enqueue account: 106, Priya, Balance: 4000
- Display Queue
- Dequeue account
- Display Queue

Expected Output:

- Account 105 is inserted into the Stack and displayed.
- Account 105 is removed from the Stack.
- Stack becomes empty.
- Account 106 is inserted into the Queue and displayed.
- Account 106 is removed from the Queue.
- Queue becomes empty.

Result: Pass
