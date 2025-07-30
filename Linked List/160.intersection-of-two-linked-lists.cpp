/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            - I have Two Solution - That is why marked easy
            - 1# Hashset - Store Address, Exist in Hashset? This is it
            - 2# Stack - For each one take a stack - push all - pop until we have difference
            - Both Take Space O(n)
            - There is an O(1) Solution somehow

            - Didn't Solve it -> Seen Solution
            - Go -> if End? start at the other head 
        */
        ListNode* first = headA;
        ListNode* second = headB;

        while(first != second){ // If no -> null == null
            first = first? first->next:headB;
            second = second? second->next:headA;
        }
        return first; // null also here
   
    }
};
// @lc code=end

