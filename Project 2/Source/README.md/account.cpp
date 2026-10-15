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
