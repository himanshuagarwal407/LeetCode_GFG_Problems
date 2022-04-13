class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int k=1;
        
        int top=0, left=0, right=n-1, bottom=n-1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left; i<=right; i++)
                mat[top][i]=k++;
            top++;
            
            for(int i=top; i<=bottom; i++)
                mat[i][right]=k++;
            right--;
            
            if(top<=bottom & left<=right)
            {
                for(int i=right; i>=left; i--)
                    mat[bottom][i]=k++;
                bottom--;
                
                for(int i=bottom; i>=top; i--)
                    mat[i][left]=k++;
                left++;
            }
        }
        
        return mat;
    }
};