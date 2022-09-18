class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        
        vector<int> lm(n);
        vector<int> rm(n);
        
        lm[0]=h[0];
        rm[n-1]=h[n-1];
        
        for(int i=1; i<n; i++)
            lm[i] = max(lm[i-1], h[i]);
        for(int i=n-2; i>=0; i--)
            rm[i] = max(rm[i+1], h[i]);
        
        int ans=0;
        for(int i=0; i<n; i++)
            ans += min(lm[i], rm[i])-h[i];
        
        return ans;
    }
};