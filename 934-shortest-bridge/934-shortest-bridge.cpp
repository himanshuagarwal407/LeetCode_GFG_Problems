class Solution {
public:
    vector<int> v1 = {0, 1, 0, -1};
    vector<int> v2 = {1, 0, -1, 0};
    
    queue<pair<int,int>>q;
    
    
    void allminusone(int i , int j , vector<vector<int>>&grid ,int row,int col)
    {
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]==0 || grid[i][j]==-1)
            return;
        
        grid[i][j]=-1;                                          
        q.push({i,j});                                         
        allminusone(i+1,j,grid,row,col);    //bottom
        allminusone(i,j+1,grid,row,col);    //right
        allminusone(i-1,j,grid,row,col);    //top
        allminusone(i,j-1,grid,row,col);    //left
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int c = 0;                     // count shortest distance
        int k = 0;
        
        // To identify 1st island and change its values
        
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(grid[i][j]==1){
                    allminusone(i,j,grid,row,col);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;
        }
        
        // using pushed cordinates to find shortest distance 
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                pair<int,int>p = q.front();
                int f = p.first;
                int s = p.second;
                q.pop();
                
                // checking distance of 2nd island 4 - directionally
                for(k=0; k<4; k++){
                    int dx = v1[k] + f;
                    int dy = v2[k] + s;
                    
                    if(dx<0 || dy<0 || dx>=row ||dy>=col ||grid[dx][dy]== -1 ) 
                        continue;
                    
                    if(grid[dx][dy]==1)
                        return c;
                    
                    grid[dx][dy]=-1;
                    q.push({dx,dy});
                }
                
            }
            c++;

        }
        return c;
    }
};