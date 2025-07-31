/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // A Solution I Didn't Think Of
       // - Store Them in Array and Index Position size()-n - Time O(n) - Space O(n)

       // But, I Don't Care I Need Better

       // Ah Man, Someone End My Suffering
       // Seen Solution:
       // - Second Pointer Start After n Nodes
       // - Go Until nullptr, First Would Be At Right Position

       ListNode* d = new ListNode();
       ListNode* prev = d; 
       prev->next = head;
       ListNode* first = head;
       ListNode* second = head;
       for (int i = 0; second && i < n; i++)
       {
           second = second->next; 
       }    
       
       while(second){
        prev = first;
        first = first->next;
        second = second->next;
       }
       prev->next = first->next;
       ListNode* result = d->next; // Head Could Be Deleted - Returning Deleted Data
       delete first; delete d;
       return result; // How Space Can More Efficient?
    }
};
// @lc code=end

