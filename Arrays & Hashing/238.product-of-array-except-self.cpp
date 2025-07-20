/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;

// Took 1 Hint
class Solution {
public:
    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]
    struct node{
        int num;
        int pre;
        int post;
        node(int num = 0,int pre = 1,int post = 1)
        :num{num},pre{pre},post{post}{}
    };
    vector<int> productExceptSelf(vector<int>& nums) {
        // Constrains: O(n) - No / operator
        // Idea: Store Prefix and Postfix for Each With minimal traversal
        // Simple Vector Should suffice
        size_t size = nums.size(); // Cache
        vector<node> nodes{}; 
        nodes.reserve(size);

        // First One - Default is 1 for pre and post since we are multiplying
        nodes.push_back(node{nums.front()});
        for(size_t i = 1; i < size; i++){ // rest of them
            int prefix = nodes[i-1].pre * nodes[i-1].num; // From previous pre and previous num
            nodes.push_back(node{nums[i],prefix}); // Make it with it's prefix
        }
        // Backward here - Update postfix - Same way
        for(int i = size-2;i >= 0;i--){
            int postfix = nodes[i+1].post * nodes[i+1].num;
            nodes[i].post = postfix;
        }

        vector<int> result{};
        result.reserve(size);
        for(size_t i = 0;i < size;i++){
            result.push_back(nodes[i].post * nodes[i].pre); // Product of pre and post is the overall product of other numbers except self
        } 
        return result;
    }
};
// @lc code=end

