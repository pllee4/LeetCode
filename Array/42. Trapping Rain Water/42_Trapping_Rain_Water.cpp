class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();

    // no able to trap water
    if (n <= 2) return 0;

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    // fill left with running max
    left[0] = height[0];
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], height[i]);
    }

    // fill right with running max
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], height[i]);
    }

    int trapped_water = 0;
    for (int i = 0; i < n; i++) {
      trapped_water += min(left[i], right[i]) - height[i];
    }
    return trapped_water;
  }
};