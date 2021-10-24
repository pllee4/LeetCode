class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int max_water = INT_MIN;

    // compute area starting from outer most boundary
    while (left < right) {
      int container = (right - left) * min(height[left], height[right]);
      max_water = max(max_water, container);
      // move left towards right if left is lower
      if (height[left] < height[right])
        left++;
      else
        right--;
    }
    return max_water;
  }
};