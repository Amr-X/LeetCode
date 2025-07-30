/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;

        ListNode* dummy_node = new ListNode(); // Dummy
        dummy_node->next = head;
        ListNode* prev = dummy_node;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next){
            if(curr->val == val){
                prev->next = next;
                delete curr;
            }else{
                prev = curr;
            }
            curr = next;
            next = next->next;
        }
        if(curr->val == val){
            prev->next = nullptr;
            delete curr;
        }
        ListNode* result = dummy_node->next;
        delete dummy_node;
        return result;
    }
};
// @lc code=end

