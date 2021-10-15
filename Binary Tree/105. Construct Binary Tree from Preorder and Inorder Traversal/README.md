# 105.Construct Binary Tree from Preorder and Inorder Traversal

## [Question](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

## Example
![tree](https://user-images.githubusercontent.com/42335542/137128592-46d566d7-acfe-4114-9078-86cbb4735343.png)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```
```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

## Approach
- Keywords:
  - Inorder (Left, Root, Right) 
  - Preorder (Root, Left, Right) 
  - Postorder (Left, Right, Root)
- For this question, we can use recursive method.
- First, we map the inorder value into its index, preorder value would be the main reference for creating new node.
- For each node, we will build the subtree.
- From the value of preorder, we will first get the position of inorder. The left of node would be based on the between begin and curInPos -1 while the right of node would be based on currInPos + 1 until the end.