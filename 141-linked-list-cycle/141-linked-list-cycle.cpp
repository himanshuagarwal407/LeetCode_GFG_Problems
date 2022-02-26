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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(head!=NULL && head->next!=NULL)
        {
            slow=slow->next;
            
            if((fast->next==NULL) || (fast->next->next==NULL))
                return false;
            
            fast=fast->next->next;
            
            if(fast==slow)
                return true;
            
            head=head->next;
        }
        
        return false;
    }
};