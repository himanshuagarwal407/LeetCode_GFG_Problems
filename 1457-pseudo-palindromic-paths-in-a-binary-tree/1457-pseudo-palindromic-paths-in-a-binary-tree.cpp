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
    int count=0;
public:
    void dfs(TreeNode* root, int path)
    {
        if(root)
        {
            path = path^(1<<root->val);
            
            if(root->left==NULL && root->right==NULL)
                if((path&(path-1))==0)
                    count++;
            
            dfs(root->left, path);
            dfs(root->right, path);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        
        return count;
    }
};