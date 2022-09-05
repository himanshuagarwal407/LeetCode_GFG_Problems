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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        
        if(!root)
            return ans;
        
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                if(q.empty())
                {
                    ans.push_back(v);
                    return ans;
                }
                else
                {
                    q.push(NULL);
                    ans.push_back(v);
                    v.clear();
                }
            }
            else
            {
                v.push_back(temp->val);
                
                for(auto x:temp->children)
                    q.push(x);
            }
            
        }
        
        return ans;
    }
};