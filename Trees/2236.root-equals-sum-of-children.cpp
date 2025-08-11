/*
 * @lc app=leetcode id=2236 lang=cpp
 *
 * [2236] Root Equals Sum of Children
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
class Solution {
public:
    // why did i pick this?
    bool checkTree(TreeNode* root) {
        return ((root->right->val + root->left->val) == root->val);
    }
};
// @lc code=end

