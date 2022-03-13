# 133. Clone Graph

## [Question](https://leetcode.com/problems/clone-graph/)
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

```
class Node {
    public int val;
    public List<Node> neighbors;
}
```

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

## Example
![example 1](https://user-images.githubusercontent.com/68624247/158055744-ff94295d-cb2d-4584-b2a2-e5b6a3b245dd.png)

```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

```
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
```

```
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
```

## Approach
- In order to create clone of graph, we use an unordered map to store the graph.
- We will keep updating the graph until all the nodes are visited through BFS
- At first we will push the node into queue and also firstly update the graph.
- After that it would be just normal BFS to explore the neighbors and if the graph does not contain the neighbors, we will add them in.
- At the same time while exploring the neighbors, we will need to add those neighbors to the graph as a cloning process.
- After all the nodes are explored, our solution would be the graph[node].