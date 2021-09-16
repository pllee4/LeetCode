# 403.Frog Jump

## [Question](https://leetcode.com/problems/frog-jump/)
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

## Example
```
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
```
```
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

## Approach
- A normal solution would be to loop through the stones and insert all the possible steps, if the last stones have the been succesfully stepped by other stone, that means it can crossed.
- The code is as below:
```
    bool canCross(vector<int>& stones) {
        vector<set<int> >v;
        set<int> steps;
        steps.insert(1);
        v.push_back(steps);
        for (int i = 1; i < stones.size(); i++) {
            steps.clear();
            for (int j = 0; j < i; j++) {
                if (v[j].find(stones[i] - stones[j]) != v[j].end())
                {
                    steps.insert(stones[i] - stones[j] - 1);
                    steps.insert(stones[i] - stones[j]);
                    steps.insert(stones[i] - stones[j] + 1);
                }
            }
            v.push_back(steps);
        }
        return (v[v.size() - 1].size() > 0);
    }
``` 
- However after glance through [Harendra Bangra](https://leetcode.com/harendra_bangra57/)'s post, memoization can reduce the runtime and memory significantly.
- Memoization is a method to store the result of previous function call to speed up the future calculation.
- Hence, recursive function can be used for this question.
- For the recusive function (cross), it will return false if the jumped position is not at any of the stones and true if the jumped position reaches the last stones. If the jumped position has been visited before, it would return the previous computed result.
- If the jumped position is not visited, the function would be recursively called by checking jump - 1, jump, and jump + 1 and return the successfulness of the jump.
