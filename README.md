Lowest Common Ancestor in Binary Tree (Please refer to the docx version of README for better understanding)


The lowest common ancestor of two nodes p and q is the lowest node in the binary tree that has p and q as its descendants.
Note: A node is also considered a descendant of itself.

Given the reference to the root node and two nodes p and q in a binary tree, return the reference to the lowest common ancestor of p and q.

Note: You can assume that p and q will be present in the tree.

lowest-common-ancestor
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 3 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The third line contains 2 space-separated integers denoting the 0-based index of p and q in the above list.
Output Format
For each test case, the output contains a line with the value of the lowest common ancestor for p and q.

Sample Input
6
7
1 2 -1 4 -1 5 6
1 5
3
6 -1 4
0 2
7
8 -1 9 -1 10 11 12
2 5
5
28 14 11 -1 48
4 2
1
6
0 0
7
3 -1 2 1 5 -1 6
3 6
Expected Output
2
6
9
28
6
1