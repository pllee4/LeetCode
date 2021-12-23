class Solution {
 public:
  int strangePrinter(string s) {
    // keep only unique character, eg. from aaabba to aba
    s.erase(unique(s.begin(), s.end()), s.end());
    // get the length of the string
    int n = s.length();
    // dp[i][j] means minimum number of turns printer need to print from i to j
    // our goal is to find dp[0][n-1]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    // k is the length of substring at a time
    for (int k = 1; k < n; k++) {
      for (int i = 0; i < n - k; i++) {
        // i represents each character in substring
        int j = i + k;
        // j represents the last character in the substring
        if (s[i] == s[j]) {
          // if it's the same character
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = INT_MAX;

          for (int l = i; l < j; l++) {
            // update and add the number of turns
            dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j]);
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};