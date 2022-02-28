class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        
        for(int i=0; i<n-1; i++)
        {
            int p=a;
            a=a+b;
            b=p;
        }
        
        return a;    
    }
};