//Source: hhttps://leetcode.com/problems/remove-duplicates-from-sorted-list/
//Author: Himanshu Agarwal
//Date:   16/01/22

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

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
        if(!head)
            return nullptr;
        
        ListNode* temp = head;
        
        while(temp->next!=NULL)
        {
            if(temp->next->val == temp->val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        
        return head;
    }
};
