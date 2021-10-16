# 236.Lowest Common Ancestor of a Binary Tree

## [Question](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

## Example
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```
```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

## Approach
- First we have a recursive function named findNode to find node from a root node.
- Its function is to find whether there is child node exists under root node.
- For lowest common ancestor, p and q would be surely be left and right of the node. In other words, while we transverse down of the root node of the binary tree, both combination (p at left, q at right or p at right, q at left) would confirm the validation of lowest common ancestor.
- The main helper function for this solution is also recursion where will we check whether p and q is at left or right.
- For each calling of helper function, the direction of traversal through the child node is determined by the location of p.
- After trying with this approach, I then found other's solution which is simpler and shorter in runtime, please refer to [simpler](https://github.com/pllee4/LeetCode/blob/master/Binary%20Tree/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree/236_Lowest_Common_Ancestor_of_a_Binary_Tree(simpler).cpp).