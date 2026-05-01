/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// Same logic for subsets but with taking the remaining of numbers
// Not just i+1 to n-1
// We need a set or a vector<bool> to indicate we took that number at this point
// of time
// - One more, We save the result at the base case When we have built a complete
// path
class Solution {
  void backtrack(vector<int> &nums, vector<int> &currentPath,
                 vector<vector<int>> &result, vector<bool> &used) {
    if (currentPath.size() == nums.size()) {
      result.push_back(currentPath);
      return;
    }
    for (int j = 0; j < nums.size(); j++) {
      if (used[j])
        continue; // Already has it in the currentPath
      // Here we loop on the remaining
      used[j] = true;
      currentPath.push_back(nums[j]);

      backtrack(nums, currentPath, result, used);

      used[j] = false;
      currentPath.pop_back();
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    vector<bool> used(n, false);     // Indicate remaining numbers
    vector<vector<int>> result = {}; // The Final Result needed
    vector<int> currentPath =
        {}; // Just a temp Vec to store the path (add/remove)
    backtrack(nums, currentPath, result, used);
    return result;
  }
};
// @lc code=end
