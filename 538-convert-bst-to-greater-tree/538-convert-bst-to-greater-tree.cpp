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
    
    void traverse(TreeNode* root, vector<pair<TreeNode*, int>>& inOrder)
    {
        if(!root)
            return;
        
        traverse(root->left, inOrder);
        inOrder.push_back(make_pair(root, root->val));
        traverse(root->right, inOrder);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        
        vector<pair<TreeNode*, int>> inOrder;
        traverse(root, inOrder);
        
        int n=inOrder.size();
        
        
        for(int i=n-2; i>=0; i--)
        {
            inOrder[i].second += inOrder[i+1].second;
            inOrder[i].first->val = inOrder[i].second;
        }
        return root;
    }
};