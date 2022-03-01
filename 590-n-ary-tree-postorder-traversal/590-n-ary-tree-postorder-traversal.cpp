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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        
        if(!root)
            return ans;
        
        stack<Node*> s1;
        stack<Node*> s2;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            Node* temp=s1.top();
            s1.pop();
            
            int i=0;
            while(i<temp->children.size())
            {
                s1.push(temp->children[i]);
                i++;
            }
            s2.push(temp);
        }
        
        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;

    }
};