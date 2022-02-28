class Solution {
public:
    int islands=0;
    void visitLand(vector<vector<int>>& grid, int i, int j, int n, int m, bool& isEdge)
    {
        if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0)
        {
            isEdge=true;
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=0)
            return ;
        
        
        
        grid[i][j]=2;     //land Visited
        
        visitLand(grid, i+1, j, n, m, isEdge);
        visitLand(grid, i, j+1, n, m, isEdge);
        visitLand(grid, i-1, j, n, m, isEdge);
        visitLand(grid, i, j-1, n, m, isEdge);
        
        // return 1;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==0)
                {
                    bool isEdge=false;
                    visitLand(grid, i, j, n, m, isEdge);
                    
                    if(!isEdge)
                        islands++;
                    
                }
        
        return islands;
    }
};