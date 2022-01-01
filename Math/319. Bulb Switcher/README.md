# 319. Bulb Switcher

## [Question](https://leetcode.com/problems/bulb-switcher/)
There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

## Example
![example1](https://user-images.githubusercontent.com/42335542/147843538-6dc59992-96e2-4a7e-9444-b9a48eaa8b43.png)
```
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.
```

```
Input: n = 0
Output: 0
```

```
Input: n = 1
Output: 1
```

## Approach
- This question is related to math divisor.
- If we list down from value of n, we will realize the number of bulbs light up would be accumulative.
- The nth bulb would be light up only if it's a perfect square.
- Hence, only nth with perfect square would have additional bulb lights up compared to n - 1.