# 96.Unique Binary Search Unique Trees

## [Question](https://leetcode.com/problems/unique-binary-search-trees/)
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

## Example
```
Input: n = 3
Output: 5
```
```
Input: n = 1
Output: 1
```

## Approach
- This question is basically about catalan number
- h(n) = h(n-1) * (4n - 2) / (n + 1)
- h(n) = 2n! / ((n + 1) * n! * n!)
- For this solution, it is using the branching method, for value of i greater than 2, the previous branched value would be added up together.