# 410.Split Array Largest Sum

## [Question](https://leetcode.com/problems/split-array-largest-sum/)
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

## Example
```
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
```
```
Input: nums = [1,2,3,4,5], m = 2
Output: 9
```
```
Input: nums = [1,4,4], m = 3
Output: 4
```

## Approach
- This question can be imagined as given number of bags, find the minimum capacity of each bag in order to put everything inside the bags one by one.
- Binary Search method is used here when we have to find the minumum capacity required.
- Starting with left bound = max(component) and right bound = sum(component)
- Algorithm of Binary Search can be found [here](https://www.geeksforgeeks.org/binary-search/)