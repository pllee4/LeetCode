class Solution {
 public:
  map<pair<int, int>, bool> dp;
  int last;
  bool canCross(vector<int>& stones) {
    if (stones[1] != 1) {
      return false;
    }
    unordered_set<int> s(stones.begin(), stones.end());
    last = stones.back();
    return cross(s, 1, 1);
  }
  bool cross(unordered_set<int>& s, int pos, int jump) {
    if (pos == last) {
      return true;
    }
    if (s.find(pos) == s.end()) {
      return false;
    }
    if (dp.find({pos, jump}) != dp.end()) {
      return dp[{pos, jump}];
    }
    bool x = false, y = false, z = false;
    if (jump - 1 > 0) {
      x = cross(s, pos + jump - 1, jump - 1);
    }
    if (!x) {
      y = cross(s, pos + jump, jump);
    }
    if (!x and !y) {
      z = cross(s, pos + jump + 1, jump + 1);
    }
    return dp[{pos, jump}] = x | y | z;
  }
};