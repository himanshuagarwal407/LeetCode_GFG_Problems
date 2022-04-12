class Solution {
public:
    bool canLive(int i, int j, vector<vector<int>>& board, int n, int m, int di[], int dj[])
    {
        int count=0;
        
        for(int k=0; k<8; k++)
        {
            int newI = i+di[k];
            int newJ = j+dj[k];
            
            if(newI>=0 && newJ>=0 && newI<n && newJ<m && board[newI][newJ]==1)
                count++;
        }
        
        if(count==3)
            return true;
        return false;
    }
    
    bool canDie(int i, int j, vector<vector<int>>& board, int n, int m, int di[], int dj[])
    {
        int count=0;
        
        for(int k=0; k<8; k++)
        {
            int newI = i+di[k];
            int newJ = j+dj[k];
            
            if(newI>=0 && newJ>=0 && newI<n && newJ<m && board[newI][newJ]==1)
                count++;
        }
        
        if(count<2 || count>3)
            return true;
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        int di[]={-1, +1, 0, 0, -1, +1, -1, +1};
        int dj[]={0, 0, +1, -1, +1, +1, -1, -1};
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==0 && canLive(i, j, board, n, m, di, dj))
                    ans[i][j]=1;
                else
                {
                    if(board[i][j]==1)
                    {
                        if(canDie(i, j, board, n, m, di, dj))
                            ans[i][j]=0;
                        else
                            ans[i][j]=1;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                board[i][j]=ans[i][j];
            }
        }
    
    }
};