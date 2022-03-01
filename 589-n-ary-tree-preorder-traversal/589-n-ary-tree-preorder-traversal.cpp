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
        vector<int> ans;
        
        if(!root)
            return ans;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty())
        {
            Node* temp=st.top();
            st.pop();
            
            ans.push_back(temp->val);
            vector<Node*> child = temp->children;
            int i=child.size()-1;
            
            while(i>=0)
            {
                st.push(child[i]);
                i--;
            }
        }
        
        return ans;
    }
};