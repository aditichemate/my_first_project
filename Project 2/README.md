
## 1. Title
BST and AVL Height Comparison Using C++

## 2. Problem Statement
To develop a C++ program that constructs a Binary Search Tree (BST) and an AVL tree using the same input sequence and compares their heights. The program also counts the number of comparisons required to search for a given key in both trees, tests ascending, descending, and random insertion orders, and displays a summary table of the results. The objective is to understand how balancing affects tree height and search efficiency.

## 3.Objective
1. To understand the construction and working of Binary Search Trees and AVL trees.
2. To compare the heights of BST and AVL trees created using the same input sequence.
3. To implement search operations and count the comparisons required in both trees.
4. To analyze the effect of ascending, descending, and random insertion orders.
5. To display a summary table comparing the height and search efficiency of both trees.

## 4.Algorithm
1. Start the program.
2. Read the number of elements and the input sequence.
3. Create an empty Binary Search Tree and an empty AVL tree.
4. Insert the given elements into the BST using the normal BST insertion method.
5. Insert the same elements into the AVL tree using AVL insertion and rotations to maintain balance.
6. Calculate the height of both trees.
7. Read a search key from the user.
8. Search for the key in the BST and count the number of node comparisons.
9. Search for the same key in the AVL tree and count the number of node comparisons.
10. Repeat the process for ascending, descending, and random insertion orders.
11. Display the height and search comparison counts of both trees in a summary table.
12. Release dynamically allocated memory.
13. Stop the program.
## 5.Flowchart
<img width="854" height="1281" alt="WhatsApp Image 2026-10-13 at 7 40 35 AM" src="https://github.com/user-attachments/assets/723452d5-028e-4d9b-8698-67f21175cda6" />

## 6. program
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for the Binary Search Tree
struct BSTNode {
int data;
BSTNode* left;
BSTNode* right;

```
BSTNode(int value) {
    data = value;
    left = right = nullptr;
}
```

};

// Insert a value into the BST
BSTNode* insertBST(BSTNode* root, int value) {
if (root == nullptr)
return new BSTNode(value);

```
if (value < root->data)
    root->left = insertBST(root->left, value);
else if (value > root->data)
    root->right = insertBST(root->right, value);

return root;
```

}

// Calculate BST height
int heightBST(BSTNode* root) {
if (root == nullptr)
return 0;

```
return 1 + max(heightBST(root->left),
               heightBST(root->right));
```

}

// Display BST inorder traversal
void inorderBST(BSTNode* root) {
if (root == nullptr)
return;

```
inorderBST(root->left);
cout << root->data << " ";
inorderBST(root->right);
```

}

// Node structure for the AVL Tree
struct AVLNode {
int data;
AVLNode* left;
AVLNode* right;
int height;

```
AVLNode(int value) {
    data = value;
    left = right = nullptr;
    height = 1;
}
```

};

// Return the height of an AVL node
int heightAVL(AVLNode* node) {
return node == nullptr ? 0 : node->height;
}

// Calculate the balance factor
int getBalance(AVLNode* node) {
if (node == nullptr)
return 0;

```
return heightAVL(node->left) -
       heightAVL(node->right);
```

}

// Perform a right rotation (LL case)
AVLNode* rightRotate(AVLNode* y) {
AVLNode* x = y->left;
AVLNode* temp = x->right;

```
x->right = y;
y->left = temp;

y->height = 1 + max(heightAVL(y->left),
                    heightAVL(y->right));

x->height = 1 + max(heightAVL(x->left),
                    heightAVL(x->right));

return x;
```

}

// Perform a left rotation (RR case)
AVLNode* leftRotate(AVLNode* x) {
AVLNode* y = x->right;
AVLNode* temp = y->left;

```
y->left = x;
x->right = temp;

x->height = 1 + max(heightAVL(x->left),
                    heightAVL(x->right));

y->height = 1 + max(heightAVL(y->left),
                    heightAVL(y->right));

return y;
```

}

// Insert a value into the AVL Tree
AVLNode* insertAVL(AVLNode* node, int value) {
if (node == nullptr)
return new AVLNode(value);

```
// Perform normal BST insertion
if (value < node->data)
    node->left = insertAVL(node->left, value);
else if (value > node->data)
    node->right = insertAVL(node->right, value);
else
    return node; // Ignore duplicate values

// Update node height
node->height = 1 + max(heightAVL(node->left),
                       heightAVL(node->right));

// Calculate balance factor
int balance = getBalance(node);

// LL case
if (balance > 1 && value < node->left->data)
    return rightRotate(node);

// RR case
if (balance < -1 && value > node->right->data)
    return leftRotate(node);

// LR case
if (balance > 1 && value > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

// RL case
if (balance < -1 && value < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

return node;
```

}

// Display AVL inorder traversal
void inorderAVL(AVLNode* root) {
if (root == nullptr)
return;

```
inorderAVL(root->left);
cout << root->data << " ";
inorderAVL(root->right);
```

}

// Free BST memory
void freeBST(BSTNode* root) {
if (root == nullptr)
return;

```
freeBST(root->left);
freeBST(root->right);
delete root;
```

}

// Free AVL memory
void freeAVL(AVLNode* root) {
if (root == nullptr)
return;

```
freeAVL(root->left);
freeAVL(root->right);
delete root;
```

}

int main() {
BSTNode* bstRoot = nullptr;
AVLNode* avlRoot = nullptr;

```
int n, value;

cout << "Enter number of values: ";

if (!(cin >> n) || n < 0) {
    cout << "Invalid number of values.\n";
    return 1;
}

cout << "Enter " << n << " integer values:\n";

for (int i = 0; i < n; i++) {
    if (!(cin >> value)) {
        cout << "Invalid input.\n";
        freeBST(bstRoot);
        freeAVL(avlRoot);
        return 1;
    }

    // Insert the same value into both trees
    bstRoot = insertBST(bstRoot, value);
    avlRoot = insertAVL(avlRoot, value);
}

cout << "\nBST Inorder Traversal: ";
inorderBST(bstRoot);

cout << "\nAVL Inorder Traversal: ";
inorderAVL(avlRoot);

cout << "\nBST Height: " << heightBST(bstRoot);
cout << "\nAVL Height: " << heightAVL(avlRoot);
cout << "\n";

freeBST(bstRoot);
freeAVL(avlRoot);

return 0;
```

}


## 7. Output
<img width="706" height="392" alt="image" src="https://github.com/user-attachments/assets/3db2da6f-16c1-4adf-9bdb-bc138961729d" />

## 8. conclusion
The project demonstrates the construction and comparison of Binary Search Trees and AVL trees using C++. It shows how insertion order affects the height of a BST and how AVL rotations maintain a balanced tree. By counting search comparisons and testing ascending, descending, and random insertion orders, the program helps evaluate the effect of tree balancing on search efficiency. Thus, AVL trees provide more predictable search performance than an ordinary BST, particularly when the BST becomes highly unbalanced.
