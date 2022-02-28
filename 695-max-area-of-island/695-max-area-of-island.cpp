class Solution {
public:
    int area=0,maxArea=0;
    
    void visitLand(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
            return;
        
        grid[i][j]=2;     //land Visited
        area++;
        visitLand(grid, i+1, j, n, m);
        visitLand(grid, i, j+1, n, m);
        visitLand(grid, i-1, j, n, m);
        visitLand(grid, i, j-1, n, m);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        
        for(int i=0; i<n; i++)
        {    
            for(int j=0; j<m; j++)
            {
                area=0;
                if(grid[i][j]==1)
                {
                    visitLand(grid, i, j, n, m);
                    islands++;
                }
                
                maxArea=(maxArea<area)?area:maxArea;
            }
        }
        
        return maxArea;
    }
};