class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x=c[1][0]-c[0][0];
        int y=c[1][1]-c[0][1];
        
        int n=c.size();
        
        for(int i=2; i<n; i++)
        {
            int x1=c[i][0]-c[0][0];
            int y1=c[i][1]-c[0][1];
            
            
            if(x1*y != y1*x)
                return false;
        }
        
        return true;
    }
};