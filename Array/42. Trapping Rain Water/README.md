# 42.Trapping Rain Water

## [Questions](https://leetcode.com/problems/trapping-rain-water/)
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## Example
![image](https://user-images.githubusercontent.com/42335542/137609154-e893e058-9744-42f5-a3bf-2fa9912bc7fd.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

## Approach
- First, we check the size of the height, if it is <= 2, no water would be able to be trapped.
- Next, we find the max continuous height from left and from right.
- The subtraction of min value (between left and right) from the height would be the actually trapped water in each unit.
- The accumulation of the trapped water would be the [answer](https://github.com/pllee4/LeetCode/blob/master/Array/42.%20Trapping%20Rain%20Water/42_Trapping_Rain_Water.cpp) for this solution.
- Nevertheless, more efficient code can be realized by using STL and stop the iteration once reach the max element for left and right.
- The single variable max_height in [here](https://github.com/pllee4/LeetCode/blob/master/Array/42.%20Trapping%20Rain%20Water/42_Trapping_Rain_Water(STL).cpp) represents the min value from previous steps. 
- [inner_product](https://en.cppreference.com/w/cpp/algorithm/inner_product) and [inclusive_scan](https://en.cppreference.com/w/cpp/algorithm/inclusive_scan) can be used to simplify the code.