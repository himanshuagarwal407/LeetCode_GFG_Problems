class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v{0,1};
        int count=1;
        
        for(int i=2; i<=n; i++)
        {
            int mod = 1<<count;
            int ind = v.size()-1;
            
            while(ind>=0)
            {
                v.push_back(v[ind]+mod);
                ind--;
            }
            
            count++;
        }
        
        return v;
    }
};