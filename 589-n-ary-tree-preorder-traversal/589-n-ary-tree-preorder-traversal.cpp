/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> preOrder;
        
        if(!root)
            return preOrder;
        
        stack<Node* > s;
        s.push(root);
        
        while(!s.empty())
        {
            Node* temp=s.top();
            s.pop();
            
            vector<Node*> v = temp->children;
            
            preOrder.push_back(temp->val);
            
            int i=v.size()-1;
            
            while(i>=0)
            {
                s.push(v[i]);
                i--;
            }
        }
        
        return preOrder;
    }
};