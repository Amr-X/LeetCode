/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next){
            curr->next = prev;
            // Next
            prev = curr;
            curr = next;
            next = next->next;
        }
        // last
        curr->next = prev;
        return curr; 
    }

    ListNode* doubleIt(ListNode* head) {
        // 445.add-two-numbers-2 would work here, But There is O(1) space solution
        // Also, Recursion or Stack Solution Works, Space O(n)

        // So, Again, Which one is better?
        // #1 No Space Created With 2 passes or 3 ...
        // #2 N Space Created But 1 Pass

        // I Will Go With First Since I Already Know 2
        // Time: O(n) Space O(1)

        ListNode* last = reverseList(head);
        ListNode* curr = last;
        int carry = 0;
        while(curr){
            int digit = 2 * curr->val + carry;
            carry = digit /10;
            (carry)? digit %= 10:0;
            // In-Place
            curr->val = digit;
            // Next
            curr = curr->next;
        }
        // Carry  
        if(carry){
            // It's Confusing Since It's Reversed
            head->next = new ListNode(carry);
            // head = head->next;  I Don't Think This Is Needed
        }
        // Forgot this one
        return reverseList(last);
    }
};
// @lc code=end

