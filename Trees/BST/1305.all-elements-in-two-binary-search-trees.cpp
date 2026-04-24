/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       // The hard part is how to traverse at the same time?
       
       // So, The easy way to put them in 2 vectors and merge -> Done..

       // What to get from here is how to traverse both at the same time
        stack<TreeNode*> stk1{};
        stack<TreeNode*> stk2{};
        TreeNode* curr1{root1}; 
        TreeNode* curr2{root2}; 

        vector<int> res;
        // get first
        if(curr1){
            while (curr1->left)
            {
                stk1.push(curr1);
                curr1 = curr1->left;
            }
        }

        if(curr2){
            while (curr2->left)
            {
                stk2.push(curr2);
                curr2 = curr2->left;
            }
        }

        while (curr1 && curr2)
        {
            if(curr1->val < curr2->val){
                res.push_back(curr1->val);
                // get next -> curr1++;
                next(curr1,stk1);
            }else{
                res.push_back(curr2->val);
                // get next -> curr2++;
                next(curr2,stk2);
            }
        }
        // The rest if one is nulled
        while(curr1){

            res.push_back(curr1->val);
            // get next -> curr1++;
            next(curr1,stk1);
        }
        while (curr2)
        {
            
            res.push_back(curr2->val);
            // get next -> curr2++;
            next(curr2,stk2);
        }
        
        return res;
        
    }
private:
    void next(TreeNode*& curr,stack<TreeNode*>& stk){
        curr = curr->right;
        if(!curr){
            if(stk.empty()){
                return;
            }
            curr = stk.top();stk.pop();
            return;
        }

        while (curr->left)
        {
            stk.push(curr);
            curr = curr->left;
        }
}
};
// @lc code=end

