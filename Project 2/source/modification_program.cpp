#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for BST and AVL tree
struct Node
{
int data;
int height;
Node* left;
Node* right;

Node(int value)
{
    data = value;
    height = 1;
    left = NULL;
    right = NULL;
}

}

// Find the height of a node
int getHeight(Node* root)
{
if (root == NULL)
return 0;

return root->height;

}

// Insert a value into the BST
Node* insertBST(Node* root, int value)
{
if (root == NULL)
return new Node(value);

if (value < root->data)
    root->left = insertBST(root->left, value);
else if (value > root->data)
    root->right = insertBST(root->right, value);

return root;

}

// Update the height of an AVL node
void updateHeight(Node* root)
{
root->height = 1 + max(getHeight(root->left),
getHeight(root->right));
}

// Find the balance factor of an AVL node
int getBalance(Node* root)
{
if (root == NULL)
return 0;

return getHeight(root->left) - getHeight(root->right);

}

// Perform right rotation
Node* rightRotate(Node* y)
{
Node* x = y->left;
Node* temp = x->right;

x->right = y;
y->left = temp;

updateHeight(y);
updateHeight(x);

return x;

}

// Perform left rotation
Node* leftRotate(Node* x)
{
Node* y = x->right;
Node* temp = y->left;

y->left = x;
x->right = temp;

updateHeight(x);
updateHeight(y);

return y;

}

// Insert a value into the AVL tree
Node* insertAVL(Node* root, int value)
{
if (root == NULL)
return new Node(value);

if (value < root->data)
    root->left = insertAVL(root->left, value);
else if (value > root->data)
    root->right = insertAVL(root->right, value);
else
    return root;

updateHeight(root);

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

// Count comparisons needed to search for a key
int searchComparisons(Node* root, int key)
{
int count = 0;
Node* current = root;

while (current != NULL)
{
    count++;

    if (current->data == key)
        return count;

    if (key < current->data)
        current = current->left;
    else
        current = current->right;
}

return count;

}

// Delete all nodes after completing a test
void deleteTree(Node* root)
{
if (root == NULL)
return;

deleteTree(root->left);
deleteTree(root->right);
delete root;

}

// Build both trees and display their results
void runTest(int values[], int n, const char* order)
{
Node* bst = NULL;
Node* avl = NULL;

// Insert the same values into both trees
for (int i = 0; i < n; i++)
{
    bst = insertBST(bst, values[i]);
    avl = insertAVL(avl, values[i]);
}

cout << "\n--- " << order << " Insertion Order ---\n";

cout << "BST Height: " << getHeight(bst) << endl;
cout << "AVL Height: " << getHeight(avl) << endl;

// Display search comparisons for each key
cout << "\nKey\tBST Comparisons\tAVL Comparisons\n";

for (int i = 0; i < n; i++)
{
    cout << values[i] << "\t"
         << searchComparisons(bst, values[i]) << "\t\t"
         << searchComparisons(avl, values[i]) << endl;
}

deleteTree(bst);
deleteTree(avl);

}

int main()
{
int n;

cout << "BST and AVL Height Comparison\n";
cout << "Enter number of elements (1 to 100): ";
cin >> n;

// Check whether the number of elements is valid
if (n < 1 || n > 100)
{
    cout << "Invalid number of elements.\n";
    return 0;
}

int input[100];
int ascending[100];
int descending[100];

cout << "Enter " << n << " distinct integers:\n";

// Read values and check for duplicates
for (int i = 0; i < n; i++)
{
    cin >> input[i];

    for (int j = 0; j < i; j++)
    {
        if (input[i] == input[j])
        {
            cout << "Duplicate values are not allowed.\n";
            return 0;
        }
    }
}

// Arrange values in ascending order
for (int i = 0; i < n; i++)
    ascending[i] = input[i];

sort(ascending, ascending + n);

// Arrange values in descending order
for (int i = 0; i < n; i++)
    descending[i] = ascending[n - 1 - i];

// Test 1: Ascending insertion order
runTest(ascending, n, "Ascending");

// Test 2: Descending insertion order
runTest(descending, n, "Descending");

// Test 3: Use the original input order
runTest(input, n, "Random/Input");

return 0;

}

