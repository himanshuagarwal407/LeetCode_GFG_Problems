// Source: https://leetcode.com/problems/reverse-linked-list/
// Author: Himanshu Agarwal
// Date: 17/01/22

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:
Input: head = [1,2]
Output: [2,1]


Example 3:
Input: head = []
Output: []


Example 4:
Input: head = [1]
Output: [1]

*/

//  *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        if(head->next == NULL)
            return head;
        
        ListNode *prev=nullptr, *curr=head;
        ListNode *next=curr->next;
        
        while(next->next)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
        while(curr)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=nullptr;
        }
        
        return prev;
    }
};
