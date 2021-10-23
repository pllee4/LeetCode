# 778.Swim in Rising Water

## [Question](https://leetcode.com/problems/swim-in-rising-water/)
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

## Example
![example1](https://user-images.githubusercontent.com/42335542/138557896-e5e16f2d-e399-4e3b-83c4-7b46794bf2dd.png)

```
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

![example2](https://user-images.githubusercontent.com/42335542/138557941-dec1b583-7e0a-4318-a7ae-01ab9abb1037.png)

```
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

## Approach
- Dijkstra's algorithm can be used in this question.
- Priority queue is used where grid with lower elevation would have higher priority.
- We will first start from the top left grid and move in 4 direction and push all the value and coordinate into the priority queue.
- Least time would be replaced whenever there is greater value of depth during the traversal where we will start from the lowest elevation from the priority queue. All the visited grid will be marked and only those unvisited would be added to the priority queue.
- As the traversal reaches, bottom right of the square, the least time would be the answer for this question.