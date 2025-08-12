/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    // Sometimes I love Recursion
    TreeNode* invertTree(TreeNode* root) {
        if(!root){return root;}

        // Very Simple Swapping The Two Subtrees
        std::swap(root->left,root->right);
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};
// @lc code=end

