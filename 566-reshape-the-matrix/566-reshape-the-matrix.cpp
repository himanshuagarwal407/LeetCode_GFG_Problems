class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        
        if(r*c != m*n)
            return mat;
        
        vector<int> temp(m*n);
        int k=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                temp[k++]=mat[i][j];
        
        vector<vector<int>> ans;
        k=0;
        for(int i=0; i<r; i++)
        {
            vector<int> a;
            for(int j=0; j<c; j++)
            {
                a.push_back(temp[k]);
                k++;
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};