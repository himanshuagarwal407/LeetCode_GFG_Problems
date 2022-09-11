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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(auto l:lists)
            if(l)
                pq.push({l->val, l});
        
        ListNode* head=nullptr;
        ListNode* prev=nullptr;
        
        while(!pq.empty())
        {
            pair<int, ListNode*> temp = pq.top();
            pq.pop();
            
            if(head==nullptr)
            {
                head=temp.second;
                prev=head;
            }
            else
            {
                prev->next = temp.second;
                prev=prev->next;
            }
            
            if(temp.second->next)
                pq.push({temp.second->next->val, temp.second->next});
        }
        
        return head;
    }
};