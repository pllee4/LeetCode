# 124.Binary Maximum Path Sum

## [Question](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

## Example
![example1](https://user-images.githubusercontent.com/42335542/138539971-5e8ee5d1-1d6c-42c5-99ee-05905c4f9a28.png)

```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
```
![example2](https://user-images.githubusercontent.com/42335542/138539995-ce7cc742-0e40-47a9-bbd5-11f44ef69207.png)

```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```

## Approach
- To calculate the maximum path sum, we can transverse through the nodes from the root node.
- For each node, the maximum path would be either addition of root node with left or right node or by chaining them together which means addition of left, right and root node.
- We can recursively transverse through the nodes and replace the max_sum whenever the conditions mentioned above are able to generate greater max_sum.