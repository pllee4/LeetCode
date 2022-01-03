# 300. Longest Increasing Subsequence

## [Question](https://leetcode.com/problems/longest-increasing-subsequence/)
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

## Example
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

## Approach
- This question can be solved using dynamic programming where dp[i] represents subsequence length for subsequence end at ith.
- If the nums[i] is greater than previous nums[j], then dp[i] would be updated and max value is preferred.
- Nevertheless, after saw solution from [Aditya Gupta](https://leetcode.com/adtyaofficial17/), I prefer his solution which is more efficient by eliminating the reduntant loop.
- His solution keeps replace vector lis with smaller value of nums[i] to achieve kind of sorting.