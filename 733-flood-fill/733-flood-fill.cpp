class Solution {
public:
    void fillColor(vector<vector<int>>& image, int i, int j, int newColor, int currColor)
    {
        if(image[i][j]==currColor)
        {
            image[i][j]=newColor;
            if(i>=1)
                fillColor(image, i-1, j, newColor, currColor);
            if(j>=1)
                fillColor(image, i, j-1, newColor, currColor);
            if(i+1 < image.size())
                fillColor(image, i+1, j, newColor, currColor);
            if(j+1 < image[0].size())
                fillColor(image, i, j+1, newColor, currColor);
        }
            
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor=image[sr][sc];
        
        if(currColor!=newColor)
            fillColor(image, sr, sc, newColor, currColor);
        
        return image;
    }
};