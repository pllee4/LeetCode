#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    // no able to trap water
    if (n <= 2) return 0;

    vector<int> max_height(n, 0);
    auto max_func = [](auto a, auto b) { return max(a, b); };
    // find position of max element
    auto max_itr = max_element(height.begin(), height.end());
    // fill from left to max element
    inclusive_scan(height.begin(), max_itr, max_height.begin(), max_func);
    // fill from right to max element
    inclusive_scan(height.rbegin(), make_reverse_iterator(max_itr),
                   max_height.rbegin(), max_func);
    // minus height from max_height and sum all of them
    return inner_product(max_height.begin(), max_height.end(), height.begin(),
                         0, std::plus<>(), std::minus<>());
  }
};