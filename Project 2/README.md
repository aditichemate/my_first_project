
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



## 6. program
#include <iostream>
using namespace std;

int main() {
    int sticks = 21;
    int user, computer;

    cout << "MATCHSTICK GAME\n";

    while (sticks > 0) {
        cout << "\nRemaining sticks: " << sticks;
        cout << "\nPick 1 to 4 sticks: ";
        cin >> user;

        if (user < 1 || user > 4 || user > sticks) {
            cout << "Invalid choice!\n";
            continue;
        }

        sticks -= user;

        if (sticks == 0) {
            cout << "You picked the last stick. You lose!\n";
            break;
        }

        computer = 5 - user;

        if (computer > sticks)
            computer = sticks;

        cout << "Computer picks "
             << computer << " sticks.\n";

        sticks -= computer;

        if (sticks == 0) {
            cout << "Computer picked the last stick. You win!\n";
            break;
        }
    }

    return 0;
}

## 7. Output
<img width="706" height="392" alt="image" src="https://github.com/user-attachments/assets/3db2da6f-16c1-4adf-9bdb-bc138961729d" />

## 8. conclusion
The project demonstrates the construction and comparison of Binary Search Trees and AVL trees using C++. It shows how insertion order affects the height of a BST and how AVL rotations maintain a balanced tree. By counting search comparisons and testing ascending, descending, and random insertion orders, the program helps evaluate the effect of tree balancing on search efficiency. Thus, AVL trees provide more predictable search performance than an ordinary BST, particularly when the BST becomes highly unbalanced.
