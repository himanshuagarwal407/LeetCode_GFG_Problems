class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea=INT_MIN;
        
        int i=0, j=n-1;
        
        while(i<j)
        {
            int h = (height[i]<height[j])?height[i]:height[j];
            int l = abs(j-i);
            int area = l*h;
            maxarea = (area>maxarea)?area:maxarea;
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return maxarea;
    }
};