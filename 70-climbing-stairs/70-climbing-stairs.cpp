class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        
        for(int i=n-2; i>=0; i--)
        {
            int p=a;
            a=a+b;
            b=p;
        }
        
        return a;    
    }
};