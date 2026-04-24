/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    // arr.size() can't be less than 2

    // Time: O(n log n) Space O(1)
    vector<vector<int>> output;

    sort(arr.begin(), arr.end());

    int abs_min = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++) {
      int value = arr[i] - arr[i - 1];
      if (value == abs_min) {
        output.push_back({arr[i - 1], arr[i]});
      } else if (value < abs_min) {
        abs_min = value;  // New diff
        output.clear();   // all before were wrong
        output.push_back({arr[i - 1], arr[i]});
      }
    }
    return output;
  }
};
// @lc code=end
