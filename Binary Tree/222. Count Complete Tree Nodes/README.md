# 222.Count Complete Tree Nodes

## [Question](https://leetcode.com/problems/count-complete-tree-nodes/)
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

## Example
![example1](https://user-images.githubusercontent.com/68624247/137584059-61a06b28-d3a6-4e03-ab98-7045d8cb6249.png)

```
Input: root = [1,2,3,4,5,6]
Output: 6
```

```
Input: root = []
Output: 0
```

```
Input: root = [1]
Output: 1
```

## Approach
- Recursive method to check the nodes, return number of children nodes and parent node