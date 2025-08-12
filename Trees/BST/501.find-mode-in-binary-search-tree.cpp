/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    int pre;
    int count;
    int max_count;
    vector<int> result;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        // If first node or value changed
        if (count == 0 || root->val != pre) {
            count = 1;
        } else {
            count++;
        }
        if (count > max_count) {
            result.clear();
            result.push_back(root->val);
            max_count = count;
        } else if (count == max_count) {
            result.push_back(root->val);
        }
        pre = root->val;
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        pre = 0; count = 0; max_count = 0; result.clear();
        inorder(root);
        return result;
    }
};
// @lc code=end

