class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                    v.push_back({i, j});
            }
        }
        
        for(int i=0; i<v.size(); i++)
        {
            int row=v[i].first;
            int col=v[i].second;
            
            for(int j=0; j<m; j++)
                mat[row][j]=0;
            for(int j=0; j<n; j++)
                mat[j][col]=0;
        }
        
    }
};