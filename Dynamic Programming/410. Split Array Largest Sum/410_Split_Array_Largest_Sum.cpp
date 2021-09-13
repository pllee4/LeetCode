class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int right = accumulate(nums.begin(), nums.end(), 0);

        auto max_left = max_element(nums.begin(), nums.end());

        int left = *max_left;
        
        while(left < right){
            int mid = (left + right) / 2;
            
            int bag = 1, sum = 0;

            for (const auto &value: nums) {
                if (sum + value > mid)
                    sum = 0, bag++;
                sum += value;
            }

            if (bag > m)
                left = mid + 1;
            else
                right = mid;
            
        }
        return left;
    }
};