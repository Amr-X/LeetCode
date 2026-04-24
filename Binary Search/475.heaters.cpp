/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int getClosestDistance(int house, vector<int>& heaters) {
    // Don't need to use upper_bound here
    auto it = lower_bound(heaters.begin(), heaters.end(), house);
    // Get the closest to the right (possibly same location)
    // To get the closest to the left - The one right before it
    int right = INT_MAX;
    int left = INT_MAX;
    if (it != heaters.end())  // No right
      right = *it - house;
    if (it != heaters.begin())  // No left
      left = house - *(--it);
    return min(right, left);
  }

 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    // Hint took: For each house Get the distance for the nearest hater

    sort(heaters.begin(), heaters.end());

    int max_radius = 0;
    for (auto& house : houses) {
      int curr = getClosestDistance(house, heaters);
      max_radius = max(max_radius, curr);
    }
    return max_radius;
  }
};
// @lc code=end
