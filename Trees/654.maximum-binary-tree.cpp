/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:
    int getMax(vector<int>& nums,int start,int end){
        int max = start;
        while(start < end){
            if(nums[start] > nums[max]){
                max = start;
            }
            start++;
        }
        return max;
    }
    TreeNode* constructTree(vector<int>& nums,int start, int end){
       if (start >= end) return nullptr;
        int maxelement = getMax(nums,start,end);
        TreeNode* new_node = new TreeNode(nums[maxelement]);
        new_node->left = constructTree(nums,start,maxelement);
        new_node->right = constructTree(nums,maxelement+1,end);
        return new_node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums,0,nums.size());        

    }
};
// @lc code=end

