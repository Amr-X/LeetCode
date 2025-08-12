/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    // Binary Searching for Integers to insert in tree - That is it
    void generateTreeWithNums(TreeNode*& root,vector<int>& nums,int i,int j){
        if(i > j){ return; } // Had to reverse it 

        int mid = (j + i) / 2; // Should this be floored???
        root = new TreeNode(nums[mid]);
        generateTreeWithNums(root->left,nums,i,mid-1);
        generateTreeWithNums(root->right,nums,mid+1,j);
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       // Easy Question Cuz Nums is Sorted 
       // Meaning you can know what is the next to be inserted and maintain it balanced
       
       // Can't Verify if it works!

       TreeNode* root{};
       generateTreeWithNums(root,nums,0,nums.size()-1);
       return root;
    }
};
// @lc code=end

