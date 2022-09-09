class Solution {
public:
    string toHex(int num) {
        string res;
        
        map<int, char> mp = {{10,'a'}, {11,'b'}, {12,'c'}, {13,'d'}, {14,'e'}, {15,'f'}};
        
        if(num==0)
            return "0";
        else if(num>0)
        {
            while(num)
            {
                int x=num%16;
                if(x>9)
                    res+=mp[x];
                else
                    res+=to_string(x);

                num/=16;
            }
        }
        else
        {
            u_int n=num;
            
            while(n)
            {
                int x=n%16;
                if(x>9)
                    res+=mp[x];
                else
                    res+=to_string(x);

                n/=16;
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};