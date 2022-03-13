class Solution {
 public:
  int numSquares(int n) {
    /* perfect squares
      examples: 1, 4, 9, 16, 25, 26

      dp[0] = 0

      base case
          dp[1] = 1

      dp[2] = 2 (1 + 1)
      dp[3] = 3 (2 + 1)


      dp[4] = 1 (4)          // perfect square
      dp[5] = 2 (4 + 1)      //always take the biggest perfect square if able to
      fit it dp[6] = 3 (4 + 1 + 1) dp[7] = 4 (4 + 1 + 1 + 1) dp[8] = 2 (4 + 4)

      // Explanation: always take the biggest perfect square if able to fit it
      // if biggest perfect square available cannot fit it, try the next biggest
      perfect square
      // choose the least number of perfect square needed

      dp[9]  = 1 (9)          // perfect square
      dp[10] = 2 (9 + 1)
      dp[11] = 3 (9 + 1 + 1)
      dp[12] = 3 (4 + 4 + 4)
      dp[13] = 2 (9 + 4)
      dp[14] = 3 (9 + 4 + 1)      or  dp[9] + dp[5]
      dp[15] = 4 (9 + 4 + 1 + 1)  or  dp[9] + dp[6]

      dp[16] = 1 (16)         // perfect square
      dp[17] = dp[16] + dp[1]
      dp[18] = dp[16] + dp[2]

      dp[n] is the least number of perfect squares numbers that sum to n
    */

    vector<int> dp(n + 1, n + 1);  // initialize with INT_MAX or just simply n+1

    // initialize base case
    dp[0] = 0;
    dp[1] = 1;

    if (n <= 1) return dp[n];

    // compute value of dp[n]
    for (int i = 2; i <= n; i++) {
      // check if it is a perfect square number
      if (ceil((double)sqrt(i)) == floor((double)sqrt(i))) {
        dp[i] = 1;
      } else {
        for (int j = 1; j * j <= i; j++) {
          dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
      }
    }
    return dp[n];
  }
};