class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // dp[i] represents subsequence length for subsequence end at ith
    // example [10,9,2,5,3,7,101,18]
    // dp[0] = 1 [10]
    // dp[1] = 1 [9]
    // dp[2] = 1 [2]
    // dp[3] = 2 [2, 5]
    // dp[4] = 2 [2, 3]
    // dp[5] = 3 [2, 3, 7]
    // dp[6] = 4 [2, 3, 7, 101]
    // dp[7] = 4 [2, 3, 7, 18]

    // Base Case
    // dp[0] = 1

    // slower
    // int N = nums.size();
    // if (N == 0) return 1;

    // std::vector<int> dp(N, 1);  // minimum subsequence value is 1
    // for (int i = 1; i < N; ++i) {
    //   for (int j = 0; j < i; j++) {
    //     if (nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
    //   }
    // }
    // return *std::max_element(dp.begin(), dp.end());

    // faster solution
    vector<int> lis;
    lis.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > lis.back()) {
        lis.push_back(nums[i]);
      } else {
        auto it = std::lower_bound(lis.begin(), lis.end(), nums[i]);
        *it = nums[i];
      }
    }

    return lis.size();
  }
};