/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy_node = new ListNode(); // Dummy
        ListNode* curr = dummy_node;
        ListNode* first = list1;
        ListNode* second = list2;

        while(first && second){
            if(first->val < second->val){
                curr->next = first;
                curr = first;
                first = first->next;
            }else{
                curr->next = second;
                curr = second;
                second = second->next;
            }
        }
        curr->next = (second)?second:first;
        ListNode* result = dummy_node->next;
        delete dummy_node;
        return result;
    }
};
// @lc code=end

