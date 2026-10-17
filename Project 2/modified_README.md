## Title: BST and AVL Tree Height and Search Comparison Using Different Insertion Orders

## Problem Statement 

To implement BST and AVL trees using C++ and compare their heights. Modify the program to count search comparisons for the same keys and test ascending, descending, and random insertion orders to analyze search efficiency.

## Objective 

1. To implement BST and AVL trees using C++.

2. To compare the heights of both trees.

3. To count search comparisons for the same keys.

4. To test ascending, descending, and random insertion orders.

5. To analyze the search efficiency of both trees.

## Algorithm

1. Start.

2. Create a BST and an AVL tree.
 
3. Prepare ascending, descending, and random insertion sequences.

4. Insert the same sequence into both trees.

5. Calculate and display the height of each tree.
 
6. Search for the same keys in both trees.
 
7. Count and display the search comparisons for each key.

8. Compare the heights and search efficiency of both trees for all three insertion orders.

9. Stop.

## sample output

Enter the number of nodes: 7
Enter the elements: 50 30 70 20 40 60 80

BST created successfully.

Finding Minimum:
Path followed: 50 -> 30 -> 20
Minimum element: 20
Comparisons required: 2

Finding Maximum:
Path followed: 50 -> 70 -> 80
Maximum element: 80
Comparisons required: 2
## Time Complexity

- BST Insertion: Average case – O(log n), Worst case – O(n).
- AVL Insertion: O(log n).
- BST Height Calculation: O(n).
- AVL Height Retrieval: O(1).
- BST Search: Average case – O(log n), Worst case – O(n).
- AVL Search: O(log n).
- Overall Time Complexity: O(n²) in the worst case due to unbalanced BST insertion and repeated searches.

## Conclusion

The program compares BST and AVL trees using ascending, descending, and random insertion orders. It calculates tree heights and counts search comparisons for the same keys. The results show that AVL trees maintain balanced heights and provide more efficient searching in the worst case than an unbalanced BST.
    


