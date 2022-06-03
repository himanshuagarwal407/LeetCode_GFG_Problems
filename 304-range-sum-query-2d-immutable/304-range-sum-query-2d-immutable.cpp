class NumMatrix {
public:
    vector<vector<int>> s;
    NumMatrix(vector<vector<int>>& matrix) {
        s=matrix;
        
        for(int k=1; k<matrix[0].size(); k++)
            s[0][k] = s[0][k-1]+matrix[0][k];
        
        for(int k=1; k<matrix.size(); k++)
            s[k][0] = s[k-1][0]+matrix[k][0];
        
        for(int i=1; i<matrix.size(); i++)
            for(int j=1; j<matrix[i].size(); j++)
                s[i][j] = s[i][j-1]+matrix[i][j]+(s[i-1][j]-s[i-1][j-1]);
    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        if(!col1 && !row1)
            sum += s[row2][col2];
        else if(!col1 && row1)
            sum = s[row2][col2]-s[row1-1][col2];
        else if(!row1 && col1)
            sum = s[row2][col2]-s[row2][col1-1];
        else
            sum = s[row2][col2]+s[row1-1][col1-1]-s[row1-1][col2]-s[row2][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */