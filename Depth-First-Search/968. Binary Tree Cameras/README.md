# 968.Binary Tree Cameras

## [Question](https://leetcode.com/problems/binary-tree-cameras/)
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

## Example
![example1](https://user-images.githubusercontent.com/42335542/138581208-9fbfd61d-c759-46fd-a269-47566297ed8c.png)

```
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
```

![example2](https://user-images.githubusercontent.com/42335542/138581214-c6c4771b-3fd4-4ba6-8c21-87ca94f861c0.png)

```
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
```

## Approach
- We can use recursive function to solve this problem.
- First, we will start to traverse the tree from the root node.
- Since the function is recursive, the first CameraState would be reflected on the fist nearest node from root node where there is no left or right node, it will be considered as Covered.
- When the parent node having left or right node as Covered, or on other words, the children nodes are not covering the parent node as there is no camera exists on children node, the parent node would be marked as Uncovered.
- As we recursively traverse, whenever there is child node that is Uncovered, it means that the parent node would need to have a camera, thus camera_num would be increased while marking parent node as Exist.
- The existence of camera on child node would mark their parent node as Covered.
- camera_num_ is passed by reference as its value would be changed during the recursion. 
- For the last node which is the root node, if it is uncovered, camera_num_ would be increased by one before it is returned as answer for this question.