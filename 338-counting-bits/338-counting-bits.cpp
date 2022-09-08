class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++)
        {
            int count=0, x=i;
            
            for(int j=0; j<32; j++)
            {
                if(x&1)
                    count++;
                x=x>>1;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};