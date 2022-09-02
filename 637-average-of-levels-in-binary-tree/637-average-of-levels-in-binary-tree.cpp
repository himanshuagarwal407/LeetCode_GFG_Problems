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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        double sum=0, count=0;
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
                        
            if(temp==NULL)
            {
                q.push(NULL);
                res.push_back(sum/count);
                sum=0;
                count=0;
                
                if(q.front()==NULL)
                    return res;
            }
            else
            {
                sum+=temp->val;
                count++;
                    
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
        }
        
        return res;
    }
};