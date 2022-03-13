# 279. Perfect Squares

## [Question](https://leetcode.com/problems/perfect-squares/)
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

## Example
```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## Approach
- Dynamic programming is used for this question.
- Carefully observe and understand the pattern and see the choices available for each try, refer to the comment at the solution.
- Basically we have to try to fit in perfect squares, with the least numbers, it perfect squares could not match or fit it, we can only continuously add 1.