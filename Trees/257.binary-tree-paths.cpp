/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // I think I overcomplicated this 
        // I want the iterative approach to be done
        if(root){
            vector<string> result;
            if(!root->left && !root->right){
                result.push_back(to_string(root->val));    
                return result;
            }
            vector<string> left_paths = move(binaryTreePaths(root->left)); // Does the move work here? lol, No Im over Checking - It's Temp vector so it will be moved you like it or not
            vector<string> right_paths = move(binaryTreePaths(root->right));
            for (auto &left_path : left_paths)
            {
            result.push_back(to_string(root->val) + "->" + left_path);
            }
            for (auto &right_path : right_paths)
            {
            result.push_back(to_string(root->val) + "->" + right_path);   
            }
            return result;

        }
        return {};
    }
};
// @lc code=end

