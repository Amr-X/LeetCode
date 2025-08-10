/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
#include <queue>
using namespace std;

class Solution {
public:
    void swap_Treenodes(vector<TreeNode*>& vec){
        // Swapping here
        size_t left = 0;
        size_t right = vec.size() -1;
        while(left < right){ 
            // swap(*vec[left],*vec[right]); fucking idiot
            swap(vec[left]->val,vec[right]->val);
            left++; right--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        // We are getting a full tree
        // Iterative
        if(!root){return nullptr;}

        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* curr{nullptr};

        int level = 0;
        // BFS
        while(!queue.empty()){
            vector<TreeNode*> vec;

            size_t queue_size = queue.size();
            for (int i = 0; i < queue_size; i++)
            {
                curr = queue.front(); queue.pop();
                // Problem: Unnecessary vec pushing if it's even level
                if(curr->left){
                    queue.push(curr->left); vec.push_back(curr->left);
                }
                if(curr->right){
                    queue.push(curr->right); vec.push_back(curr->right);
                }
            } // We now have the all new level locations in the queue
            level++;

            if(!vec.empty() && level % 2 != 0){  // Odd Level
                swap_Treenodes(vec);
            }
        }
        return root;
        /*
            - I WANT TO SLEEP GET ME IN BED ASAP
        */
    }
};
// @lc code=end

