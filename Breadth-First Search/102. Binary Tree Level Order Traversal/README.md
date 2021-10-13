# 102.Binary Tree Level Order Traversal

## [Question](https://leetcode.com/problems/binary-tree-level-order-traversal/)
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

## Example
![tree](https://user-images.githubusercontent.com/42335542/137128592-46d566d7-acfe-4114-9078-86cbb4735343.png)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```
```
Input: root = [1]
Output: [[1]]
```
```
Input: root = []
Output: []
```

## Approach.
- First, we push the root node into queue, followed by a nullptr.
- nullptr is acting as delimiter signify end of each level of node. Once the delimiter is reached, previous nodes value in same value would be pushed into result followed by clearing of curr_level vector.
- As long as there is queue which is not empty, we pop the node from the queue and store the node value accordingly while pushing back the available children nodes into the queue to continue iterate all the available children nodes.
