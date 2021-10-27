class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    unordered_map<char, int> last_occur;
    // store last occurrence of respective letters
    for (int i = 0; i < n; i++) last_occur[s[i]] = i;

    int left = 0, right = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      // update right to be max value last occurrence of letters
      right = max(right, last_occur[s[i]]);
      // reaching last occurrence of letters
      if (i == right) {
        ans.push_back(i - left + 1);
        // update left position
        left = i + 1;
      }
    }
    return ans;
  }
};