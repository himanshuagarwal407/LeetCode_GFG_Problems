class Solution {
public:
    
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        int tSum=cp[0];
        int sum=0;
        
        for(int i=1; i<n; i++)
        {
            tSum+=cp[i];
            cp[i]+=cp[i-1];
        }
        
        if(n==k)
            return tSum;
        
        int wSum=0;
        cp.insert(cp.begin(), 0);
        
        k=n-k;
        for(int i=1; i+k-1<=n; i++)
        {
            wSum=cp[i+k-1]-cp[i-1];
            
            sum = max(sum, tSum-wSum);
        }
        
        return sum;
    }
};