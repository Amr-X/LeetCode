/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(!root){return 0;}

        int r_d = minDepth(root->right);
        int l_d = minDepth(root->left);
        if(r_d == 0 || l_d == 0){ // The Tricky Part -> If Skewed tree min depth is not zero
            return r_d + l_d + 1; // One of it zero then the other + 1 
        }
        return (r_d < l_d)?r_d+1:l_d+1;
    }
};
// @lc code=end

