# 763. Partition Labels

## [Question](https://leetcode.com/problems/partition-labels/)
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.

## Example
```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```

```
Input: s = "eccbbbbdec"
Output: [10]
```

## Approach
- First, we store the last occurrence of each letters from string s.
- We then start to check the letters from starting of string s.
- From the first letter, its last occurrence supposed to be the end of first partition. However, if any of the letters before last occurrence value of first letter having greater value of last occurrence, the right value would be replaced by that last occurrence of that letter.
- Only when we reach the right value, a partition can be formed.