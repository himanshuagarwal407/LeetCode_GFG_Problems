class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        int n =v.size();
        
        sort(v.begin(), v.end());
        
        while(true)
        {
            n=v.size();
            
            if(n==1)
                return v[0];
            if(n==0)
                return 0;
            
            int y=v[n-1], x=v[n-2];
            
            v.pop_back();
            v.pop_back();
            
            if(y!=x)
            {
                v.push_back(y-x);
                sort(v.begin(), v.end());
            }
            
        }
        
    }
};