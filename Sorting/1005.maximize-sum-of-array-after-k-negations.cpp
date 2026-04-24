/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    vector<int> result(nums.begin(), nums.end());  // Can avoid this
    sort(result.begin(), result.end());
    // Flipping negatives
    int i = 0;
    for (; k > 0 && i < result.size() && result[i] < 0;
         i++, k--) {  // K times modification
      result[i] *= -1;
    }
    // We hit a positive number -> Why Negate it when we can negate
    if (k % 2) {  // 0 -> if even -> do nothing -> ex. 1 -> -1 -> 1 (2 flips)
      // 1 -> if odd -> we have to flip something
      // But what to flip? The closest to 0 (smallest abs value)
      int idx;
      if (i == 0) {
        idx = 0;
      } else if (i == result.size()) {
        idx = i - 1;
      } else {
        idx = (abs(result[i]) < abs(result[i - 1])) ? i : i - 1;
      }

      result[idx] *= -1;
    }
    // Getting the sum
    int sum = 0;
    for (auto& num : result) sum += num;
    return sum;
  }
};
// @lc code=end
