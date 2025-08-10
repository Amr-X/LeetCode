/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
       // Structure is the same
       // Any traversal will do -- No need after Thinking
       // If This works, HOLY SHIT
       if(!p || !q){
        return(p == q);
       }
       return ((p->val == q->val) && isSameTree(p->right,q->right) && isSameTree(p->left,q->left));
    }
};
// @lc code=end

