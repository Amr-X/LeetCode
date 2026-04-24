/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    // Sorting to know which monsters are first (closest) to us
    // Sort what? the time they need to arrive t=d/s
    vector<double> time(dist.size());
    for (int i = 0; i < dist.size(); i++) {
      time[i] = dist[i] / (double)speed[i];
    }
    sort(time.begin(), time.end());

    // Here is the hard part -> I couldn't understand it
    // We go minute by minute i -> current minute
    // And try to kill a monster only if i < time[i]
    // at minute = 1 we can kill anything that will arrive in more than a minute
    // at minute = 4 we can kill anything that will arrive in more than 4 min
    // [5,6,7,..] (float numbers too) We can't kill a monster that will arrive
    // in less than or equal 4 min

    int count = 0;
    for (int i = 0; i < dist.size() && i < time[i]; i++) count++;
    return count;
    // or, time[i] - i > 0 <- More intuitive
  }
};
// @lc code=end
