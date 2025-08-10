/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSym(TreeNode* first,TreeNode* second){
        // Same Thing
        if(!first || !second){ return(first == second); }        

        return (
        (first->val == second->val)
        && (isSym(first->right,second->left) // This Part is Diff
        && (isSym(first->left,second->right)))); // And this ofc
    }
    bool isSymmetric(TreeNode* root) {
        // My Bad, Understood it wrong
        return (isSym(root->right,root->left));
    }
};
// @lc code=end

