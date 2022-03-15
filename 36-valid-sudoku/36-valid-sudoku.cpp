class Solution {
public:
    bool grid3x3(vector<vector<char>>& board, int row, int col)
    {
        unordered_set<char> s;
        for(int i=row; i<row+3; i++)
        {
            for(int j=col; j<col+3; j++)
            {
                char c=board[i][j];
                int x=int(c);
                if(x>=49 && x<=57)
                {
                    if(s.count(board[i][j])==1)
                    {
                        cout << "grid" << endl;
                        return true;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //check for row validation
        for(int i=0; i<9; i++)
        {
            unordered_map<char, int> map;
            for(int j=0; j<9; j++)
            {
                char c=board[i][j];
                int x=int(c);
                
                if(x>=49 && x<=57)
                {
                    if(map.find(c)!=map.end())
                    {
                        return false;
                    }
                    else
                    {
                        map[c]=1;
                    }
                }
            }
        }
        
        //check for column validation
        for(int i=0; i<9; i++)
        {
            unordered_map<char, int> map;
            for(int j=0; j<9; j++)
            {
                char c=board[j][i];
                int x=int(c);
                
                if(x>=49 && x<=57)
                {
                    if(map.find(c)!=map.end())
                    {
                        return false;
                    }
                    else
                    {
                        map[c]=1;
                    }
                }
            }
        }
        
        //check for 3x3 grid validation
        for(int i=0; i<9; i=i+3)
        {
            for(int j=0; j<9; j=j+3)
            {
                if(grid3x3(board, i, j))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};