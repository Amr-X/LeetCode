/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        // 3 Pointers
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy; prev->next = head;
        ListNode* curr = head;
        ListNode* next = (head->next)?head->next:nullptr;

        while(next){
            if(curr->val == next->val){
                prev->next = next;
                delete curr;
                curr = next;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
            next = next->next;
        }
        ListNode* result = dummy->next;
        delete dummy; 
        return result; 
    }
};
// @lc code=end

