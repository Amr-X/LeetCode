/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
#include <vector>

#include "algorithm"
using namespace std;

class Solution {
 public:
  // Time -> O(nlogn) Space -> O(1);
  int arrayPairSum(vector<int>& nums) {
    // Sort
    sort(nums.begin(), nums.end());

    // We don't need all pairs just the optimal one
    // [2,3,5,7,10,11] -> (2,3),(5,7),(10,11)
    //                      2  ,  5  , 10  -> 17

    // How? We want a the pairs to have a big number right? so we would like to
    // get 11 and 10 and so on So to take a pair that has a big number like (11)
    // should we take min(11,10) -> 10 <- The biggest one after Or take
    // min(11,2) or with 3 or 5 or 7 -> 2 <- the small number is the min so we
    // take pairs that are next to each other -> That easy

    int result = 0;
    for (int i = 0; i < (int)nums.size() - 1; i += 2) {
      //   result += min(nums[i], nums[i + 1]);  that was too stupid
      result += nums[i];
    }
    return result;
  }
};
// @lc code=end
