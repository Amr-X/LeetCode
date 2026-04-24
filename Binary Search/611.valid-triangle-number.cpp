/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 private:
  // Original
  int searchCeil(vector<int>& sorted, int a_b, int start = 0) {
    if (sorted.empty()) return 0;
    int l = start;
    int r = sorted.size() - 1;
    int idx = sorted.size();  // or idx = start - 1;
    while (r >= l) {
      int m = (l + r) / 2;
      if (sorted[m] >= a_b) {  // or >
        // c < a+b? -> Note: This will get the first occurance of the
        // number (lower bound) or next greater
        idx = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    return idx - start;  // or +1
  }
  int triangleNumber1(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    vector<int>& sorted = nums;
    sort(sorted.begin(), sorted.end());
    // [a <= b <= c]
    // To meet the property of c+b > a and c+a > b
    int result = 0;
    for (int i = 0; i < sorted.size() - 2; i++) {
      if (sorted[i] == 0) continue;
      for (int j = i + 1; j < sorted.size() - 1; j++) {
        // The Key solution here is get how many sides are between nums[i+1] ->
        // (a+b)
        result += searchCeil(sorted, sorted[i] + sorted[j], j + 1);
      }
    }
    return result;
  }

 public:
  // STL based
  int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    vector<int>& sorted = nums;
    sort(sorted.begin(), sorted.end());
    int result = 0;

    for (int i = 0; i < sorted.size() - 2; i++) {
      if (sorted[i] == 0) continue;
      for (int j = i + 1; j < sorted.size() - 1; j++) {
        // Don't have to do j+1 here but doesn't hurt to be specific
        auto upper = upper_bound(sorted.begin() + j + 1, sorted.end(),
                                 sorted[i] + sorted[j] - 1);
        // Remember: Upper points to next greater element
        result += (upper - (sorted.begin() + j + 1));
      }
    }
    return result;
  }
};
// @lc code=end
