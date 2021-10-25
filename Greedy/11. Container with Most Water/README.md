# 11.Container with Most Water

## [Question](https://leetcode.com/problems/container-with-most-water/)
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

## Example

![example1](https://user-images.githubusercontent.com/42335542/138720850-a99a70ee-d50e-4657-b01f-68c67fbd598b.png)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

Example 2:
```
Input: height = [1,1]
Output: 1
```

Example 3:
```
Input: height = [4,3,2,1,4]
Output: 16
```

Example 4:
```
Input: height = [1,2,1]
Output: 2
```

## Approach
- [Two Pointers Technique](https://medium.com/swlh/two-pointer-technique-solving-array-problems-at-light-speed-56a77ee83d16) can be used for this problem.
- We will start from most left and most right, we will shift the one with lower height towards its opposite direction and keep update the max_water level.