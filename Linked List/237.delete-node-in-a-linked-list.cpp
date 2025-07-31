/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       // First Thought Of This --> This Question Should Be Easy.. I'm Not Bragging Here 

    //    ListNode* curr = node;
    //    ListNode* next = node->next;

    //    while(next->next){
    //     std::swap(curr->val,next->val);
    //     curr = curr->next;
    //     next = next->next;
    //    }
    //    // Last
    //    std::swap(curr->val,next->val);
    //    curr->next = nullptr; // last
    //    delete next;

    // Yeah, Im an Idiot - Optimal O(1) time and space
        if(!node) return;
        if(!node->next){
            // READABILITY MAN
            delete node;
            return;
        }

        ListNode* curr = node;
        ListNode* next = node->next;

        curr->val = next->val;
        curr->next = next->next; // Connected
        delete next;
    }
};
// @lc code=end

