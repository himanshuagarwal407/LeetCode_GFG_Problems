class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> res(n, vector<int>(m,10000));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                    res[i][j]=0;
                else
                {
                    if(i>0)
                        res[i][j] = min( res[i-1][j]+1, res[i][j]);
                    if(j>0)
                        res[i][j] = min( res[i][j-1]+1, res[i][j]);
                }
            }
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                    if(i+1<n)
                        res[i][j] = min( res[i+1][j]+1, res[i][j]);
                    if(j+1<m)
                        res[i][j] = min( res[i][j+1]+1, res[i][j]);
            }
        }
        
        return res;
    }
};