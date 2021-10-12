# 743.Netowrk Delay Time

## [Question](https://leetcode.com/problems/network-delay-time/)
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

## Example
```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```
```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```
```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

## Approach
- Djiikstra algorithm can be used for this question.
- The distance travelled to each node has to be stored and can be computed based on the nearest node distance.
- Adj vector represents the source node with pair of travel time and destination node.
- As long as k has never been as a source, it shall return -1.
- Next, we have a priority queue for travel time and destination where less travel time has more priority, this is to ensure we can mark the minimum travel time to reach the node.
- At first, we will start from k source node.
- Since it is the source node that we wish to start off, the priority queue would be {0, k} as no travel time is needed.
- As we use node number as index, dist[0] would never been considered in computation, hence we can mark it as 0 or anything as long as not INT_MAX.
- We will start with node as k first, all those unvisited nodes (dis[node] = INT_MAX) would be replaced with dist if they are present in the source node vector.
- The child with the pushed into priority queue and continue to be looped.
- If the child is not presented in the adj[], it will be skipped and keep popping the priority queue until it becomes empty.
- In the end, if there is node that has never been visited before, -1 will be returned.
- Else, max value of dist[node] will be returned. 
