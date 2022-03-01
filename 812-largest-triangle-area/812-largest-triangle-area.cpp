class Solution {
public:
    double area(vector<int> a, vector<int> b, vector<int> c)
    {
        double D = abs(a[0]*b[1] + a[1]*c[0] + b[0]*c[1] - b[1]*c[0] - a[1]*b[0] - a[0]*c[1]);
        
        return D/2.00000;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
       int n=points.size();
        
        double maxArea=INT_MIN;
        
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }
        
        return maxArea;
    }
};