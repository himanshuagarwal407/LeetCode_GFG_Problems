class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int param=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    if(i==0)
                        param++;
                    else if(grid[i-1][j]==0)
                        param++;
                    if(i==n-1)
                        param++;
                    else if(grid[i+1][j]==0)
                        param++;
                    
                    if(j==0)
                        param++;
                    else if(grid[i][j-1]==0)
                        param++;
                    if(j==m-1)
                        param++;
                    else if(grid[i][j+1]==0)
                        param++;
                }
            }
        }
    
        return param;
    }
};