# 664.Strange Printer

## [Question](https://leetcode.com/problems/strange-printer/)
There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

## Example
```
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
```
```
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
```

## Approach
- First, we ensure the only unique characters left int the string.
- Dynamic programming would be used to treat the question as smaller components.
- dp[i][j] represents the single character that is required to be printed from i to j, our goal is to find dp[0][n-1].
- Initialize each dp[i][i] with 1 which represents the minimum number of turns printer need to print for each character.
- Check if the character is the same, the value of dp[i][j] would be equivalent to the previous value.
- If it's not the same, then the value of dp[i][j] would be marked as INT_MAX.
- Loop through the value of till j to update the value of dp[i][j].
- The solution would be the value of dp[0][n-1].