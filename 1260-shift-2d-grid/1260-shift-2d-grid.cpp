class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        
        k = k%(n*m);
        
        if(k>=m)
        {
            
            int x=k/m;
            k=k%m;
            
            for(int i=0; i<x; i++)
            {
                grid.insert(grid.begin(), grid[n-1]);
                grid.pop_back();
            }
        }
        while(k--)
        {
            grid[0].insert(grid[0].begin(), grid[n-1][m-1]);
            grid[n-1].pop_back();
            
            for(int i=0; i<n-1; i++)
            {
                grid[i+1].insert(grid[i+1].begin(), grid[i][m]);
                grid[i].pop_back();
            }
        }
        
        return grid;
    }
};