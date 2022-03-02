class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        
        while(1)
        {
            int sos=0;
            do
            {
                int x=n%10;
                sos+= x*x;
                n/=10;
            }   
            while(n);
            
            if(sos==1)
                return true;
            
            if(s.find(sos)!=s.end())
                return false;
            s.insert(sos);
            n=sos;
        }
        
        return false;
    }
};