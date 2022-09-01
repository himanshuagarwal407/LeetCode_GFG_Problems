class Solution {
public:
    bool solve(vector<vector<bool>>& ocean, int n, int m,int row, int col, vector<vector<int>>& h)
    {
        if(row<0 || row==n || col<0 || col==m || h[row][col]==INT_MAX)
            return false;
        
        if(ocean[row][col])
            return true;
        
        int k=h[row][col];
        h[row][col]=INT_MAX;
        bool f=false;
        
        if(row>0 && h[row-1][col]<=k)
            f=f||solve(ocean, n, m, row-1, col, h);
        if(col>0 && h[row][col-1]<=k)
            f=f||solve(ocean, n, m, row, col-1, h);
        if(row<n-1 && h[row+1][col]<=k)
            f=f||solve(ocean, n, m, row+1, col, h);
        if(col<m-1 && h[row][col+1]<=k)
            f=f||solve(ocean, n, m, row, col+1, h);
        
        ocean[row][col]=f;
        h[row][col]=k;
        
        return f;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)
        {
            pac[i][0]=true;
            atl[i][m-1]=true;
        }
        for(int i=0; i<m; i++)
        {
            pac[0][i]=true;
            atl[n-1][i]=true;
        }
        
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(solve(pac, n, m, i, j, h) && solve(atl, n, m, i, j, h))
                    ans.push_back({i, j});
            }
        }
        
        return ans;
        
    }
};