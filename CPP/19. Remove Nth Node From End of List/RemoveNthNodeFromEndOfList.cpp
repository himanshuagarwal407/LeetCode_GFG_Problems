// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: Himanshu Agarwal
// Date: 19/01/22
  
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:
Input: head = [1], n = 1
Output: []


Example 3:
Input: head = [1,2], n = 1
Output: [1]


*/
  
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
        if(!head)
            return nullptr;
        
        if(!head->next)
            return nullptr;
        
        ListNode* temp = head;
        
        int size=0;
        while(temp->next)
        {
            size++;
            temp=temp->next;
        }
        size++;
        
        if(size==n)
            return head->next;
        
        temp = head;
        for(int i=1; i<size-n; i++)
            temp=temp->next;
        
        if(temp->next->next)
            temp->next=temp->next->next;
        else
            temp->next=NULL;
        
        return head;
    }
};
