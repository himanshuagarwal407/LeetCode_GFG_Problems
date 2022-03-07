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
private:
    int sMin = INT_MAX;
    int flag = 0;
public:
    void findMin(TreeNode* root, int min)
    {
        if(!root)
            return;
        
        if(root->val == min)
        {
            findMin(root->left, min);
            findMin(root->right, min);
        }
        else if(root->val > min && root->val <= sMin)
        {
            sMin=root->val;
            flag=1;
            return;
        }
        
        return;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        
        findMin(root, min);
        
        if(flag==1)
            return sMin;
        
        return -1;
    }
};