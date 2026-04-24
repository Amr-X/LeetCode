/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    // 3 size array

    // Sort. Why? Make the biggest pieces (sides) at the end (or start) <<-
    sort(nums.begin(), nums.end(), greater<int>());

    // [10,2,1,1]

    for (int i = 0; i < (int)nums.size() - 2; i++) {
      // Take [10,2,1,-----] is it valid?
      // By sorting -> 2 < 1 + 10 , 1 < 10 +2 is always true - We don't have to
      // check them
      if (nums[i] < nums[i + 1] + nums[i + 2]) {
        // only one left -> 2+1 > 10? No in this case
        // But, What if [20,14,13] 13+14 > 20? Yes , The next two number (that
        // are less than 20) could be 19 + 18 (true) or could be 2 + 1 (False)
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
    // We don't have to know other valid ones since we starting from the max
    // side and next two (100,88,2,.....) will always be larger then ........
  }
};
// @lc code=end
