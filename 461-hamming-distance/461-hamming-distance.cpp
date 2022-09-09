class Solution {
public:
    int setBits(int n)
    {
        int count=0;
        
        while(n)
        {
            if(n&1)
                count++;
            n=n>>1;
        }
        
        return count;
    }
    
    int hammingDistance(int x, int y) {
        int count=0;
        
        while(x!=0 && y!=0)
        {
            // cout << x << " " << y << endl;
            
            auto a = x&1, b=y&1;
            if(a != b)
            {
                count++;
                // cout << "yes" << endl;
            }
            
            x=x>>1;
            y=y>>1;
        }
        // cout << count ;
        if(y!=0)
            count+=setBits(y);
        if(x!=0)
            count+=setBits(x);
        
        return count;
    }
};