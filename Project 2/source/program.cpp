#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// Insert into BST
Node* insertBST(Node* root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}

// Calculate BST height
int heightBST(Node* root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(heightBST(root->left),
                   heightBST(root->right));
}

// Get height of AVL node
int getHeight(Node* node)
{
    if (node == nullptr)
        return 0;

    return node->height;
}

// Calculate balance factor
int getBalance(Node* node)
{
    if (node == nullptr)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert into AVL tree
Node* insertAVL(Node* root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertAVL(root->left, value);
    else if (value > root->data)
        root->right = insertAVL(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // Left Left case
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right case
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right case
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left case
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display tree height
void displayHeight(Node* bst, Node* avl)
{
    cout << "\nBST Height: " << heightBST(bst);
    cout << "\nAVL Height: " << getHeight(avl);

    if (heightBST(bst) > getHeight(avl))
        cout << "\nAVL tree has smaller height.\n";
    else if (heightBST(bst) < getHeight(avl))
        cout << "\nBST has smaller height.\n";
    else
        cout << "\nBoth trees have equal height.\n";
}

// Free allocated memory
void deleteTree(Node* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Node* bst = nullptr;
    Node* avl = nullptr;

    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of elements.\n";
        return 0;
    }

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        bst = insertBST(bst, value);
        avl = insertAVL(avl, value);
    }

    cout << "\n--- BST and AVL Height Comparison ---";
    displayHeight(bst, avl);

    deleteTree(bst);
    deleteTree(avl);

    return 0;
}
