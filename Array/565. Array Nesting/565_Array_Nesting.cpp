class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    int res = 0;
    for (int i= 0; i < nums.size(); i++) {
        if (nums[i] == -1) continue;
        int index = i;
        int value = nums[i];
        int count = 0;
        while (nums[index] != -1) {
            nums[index] = -1;
            count++;
            index = value;
            value = nums[index];
        }
        if (count > res)
            res = count;
    }
    return res;
    }
};