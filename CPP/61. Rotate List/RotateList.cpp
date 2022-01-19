// Source: https://leetcode.com/problems/rotate-list/
// Author: Himanshu Agarwal
// Date: 19/01/22
  
/*

Given the head of a linked list, rotate the list to the right by k places.

 
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        
        if(!head->next)
            return head;
        
        ListNode* temp = head;
        int size=1;
        while(temp->next)
        {
            size++;
            temp=temp->next;
        }
        
        k=k%size;
        
        if(k==0)
            return head;
        
        temp=head;
        for(int i=1; i<size-k; i++)
            temp=temp->next;
        
        ListNode* rot=temp->next;
        temp->next=NULL;
        
        temp=head;
        head=rot;
        while(rot->next)
            rot=rot->next;
        rot->next=temp;
        
        return head;
    }
};
