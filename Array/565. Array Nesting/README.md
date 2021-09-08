# 565.Array Nesting

## [Question](https://leetcode.com/problems/array-nesting/)
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.
The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
We stop adding right before a duplicate element occurs in s[k].
Return the longest length of a set s[k].

## Example
Input: nums = [5,4,0,3,1,6,2]
Output: 4

Input: nums = [0,1,2]
Output: 1

## Approach
- Since it is like a graph like problem, not matter which value of index is true for looping, the cycle will continue until the loop is closed
- Hence, mark visited num as -1 and never check it again
- If it is not visited, keep looping the value of index for the rest of the array and increase the count
- Get the max count