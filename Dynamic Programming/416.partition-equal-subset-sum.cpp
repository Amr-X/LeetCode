/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  // Dp state depends on the current item to take or leave and the total sum of
  // the decisions so far (instead of the whole vector<choice>)
  // Dp is 3d F(idx,sumTook,sumLeft) (My Original Way) but it can be reduced to
  // F(idx,total) and check if total is 0

  // Instead of building up the total
  // bool canPartition(vector<int> &nums, int i, int total) {

  //   // We check at the end
  //   if (i >= nums.size())
  //     return total == 0;

  //   bool take = canPartition(nums, i + 1, total + nums[i]);
  //   bool leave = canPartition(nums, i + 1, total);
  //   return take || leave;
  // }
  bool canPartition(vector<int> &nums, int i, int target,
                    vector<vector<int>> &dp) {

    if (target < 0)
      return false;

    if (i >= nums.size())
      return target == 0;

    int &result = dp[i][target];
    if (result == -1) {
      bool take = canPartition(nums, i + 1, target - nums[i], dp);
      bool leave = canPartition(nums, i + 1, target, dp);

      result = take || leave;
    }
    return result;
  }

public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
      return false; // Can't split a number into two equal halfs
    int target = sum / 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return canPartition(nums, 0, target, dp);
  }
};

// @lc code=end
