class Solution {
public:
    void visitLand(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1')
            return;
        
        grid[i][j]='2';     //land Visited
        
        visitLand(grid, i+1, j, n, m);
        visitLand(grid, i, j+1, n, m);
        visitLand(grid, i-1, j, n, m);
        visitLand(grid, i, j-1, n, m);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]=='1')
                {
                    visitLand(grid, i, j, n, m);
                    islands++;
                }
        
        return islands;
    }
};