/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> inOrder;
        
        if(!root)
            return inOrder;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(nullptr);
        vector<int> v;
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==nullptr)
            {
                inOrder.push_back(v);
                v.clear();
                if(!q.empty())
                    q.push(nullptr);
            }
            else
            {
                v.push_back(temp->val);
            
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return inOrder;
    }
};