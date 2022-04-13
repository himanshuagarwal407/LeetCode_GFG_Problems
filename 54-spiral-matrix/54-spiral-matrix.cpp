class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        
        int n=mat.size();
        int m=mat[0].size();
        
        int top=0, left=0, right=m, bottom=n;
        
        while(top<bottom && left<right)
        {
            for(int j=left; j<right; j++)
                ans.push_back(mat[top][j]);
            top++;
            
            for(int j=top; j<bottom; j++)
                ans.push_back(mat[j][right-1]);
            right--;
            
            if(top<bottom && left<right)
            {    
                for(int j=right-1; j>=left; j--)
                    ans.push_back(mat[bottom-1][j]);
                bottom--;

                for(int j=bottom-1; j>=top; j--)
                    ans.push_back(mat[j][left]);
                left++;
            }
        }
        
        return ans;
    }
};