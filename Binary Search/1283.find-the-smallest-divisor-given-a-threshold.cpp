/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
#include <math.h>

#include <algorithm>
#include <vector>

using namespace std;
class Solution {
 public:
  int sum(vector<int>& nums, int divisor) {
    int curr_result = 0;
    for (const auto& num : nums) curr_result += ceil(num / (double)divisor);
    return curr_result;
  }
  // Here is the monotonic function
  // [f,f,f,f,f,f,(t),t,t,t,t,t,t] -> Infinity
  // (t) -> Is what we need
  // Condition sum(nums,divisor) <= threshold
  int smallestDivisor(vector<int>& nums, int threshold) {
    // Misunderstood what the threshold was - 1H wasted
    int l = 1;
    int r = INT_MAX;  // INT_MAX is big value - It could be The Max integer from
                      // nums instead
    // Could be changed to the max of the nums -> O(n)
    int save = INT_MAX;  // A very big number will get us [1,1,1,1] all ones the
                         // possible lowest sum
    // But not only this number will get us that - We need the Minimum that get
    // the same result (Look at the monotonic function above)
    while (l <= r) {
      int divisor = l + (r - l) / 2;
      int s = sum(nums, divisor);
      if (s <= threshold) {
        save = divisor;
        r = divisor - 1;
      } else
        l = divisor + 1;
    }
    return save;
  }
};
// @lc code=end
