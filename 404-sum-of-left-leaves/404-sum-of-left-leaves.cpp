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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        
        while(!q.empty())
        {
            temp=q.front();
            if(temp->left)
            {
                q.push(temp->left);
                if(temp->left->left==NULL && temp->left->right==NULL)
                    sum+=temp->left->val;
            }
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
        
        return sum;
    }
};