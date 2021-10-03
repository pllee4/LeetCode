# 994.Rotting Oranges

## [Question](https://leetcode.com/problems/rotting-oranges/)
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

## Example
```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```
```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```
```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```

## Approach
- For this problem, there are two situations where no further computation is needed: 
  - If there is no fresh orange, return 0.
  - If there is fresh orange but there is no rotten orange, return -1.
- Other than this, Breadth First Search method can be used for this problem.
- First, we will add vertex of all rotten oranges into queue
- Then we will traverse all the rotten oranges at 4-directionally adjacent, whenever there is fresh orange, it would be marked as rotten.
- n is kept as previous number of rotten oranges as there may have fresh oranges that would become rotten after the traverse.
- If there is fresh orange which becomes rotten, the grid would be pushed into the queue thus causing increase in queue size then previous, thus minutes would be increased by one.
- The process continues until there is no more new rotten oranges (queue).
- In the end, if there is still fresh orange, -1 would be returned else minutes would be returned.