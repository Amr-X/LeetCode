/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
  long square(long x) { return x * x; }

 public:
  // Could use just normal integers
  int mySqrt(int x) {
    if (x < 2) return x;
    // x = 30
    // Think of using the calculator as a kid
    // You know the answer is between 5(25) and 6(36)
    int l = 0;
    int r = x;  // Very importand to konw the max search space
    int save = 0;
    while (l <= r) {
      int possible_value = l + (r - l) / 2;
      if (square(possible_value) > x) {
        save = possible_value;
        r = possible_value - 1;
      } else
        l = possible_value + 1;
    }
    return save - 1;
  }
};
// @lc code=end
