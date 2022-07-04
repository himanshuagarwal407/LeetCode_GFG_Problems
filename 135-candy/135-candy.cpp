class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int> candy(n,1);
        
        for(int i=1; i<n; i++)
        {
            if(rat[i-1]<rat[i])
                candy[i]=candy[i-1]+1;
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(rat[i]>rat[i+1] && candy[i]<=candy[i+1])
                candy[i]=candy[i+1]+1;
        }
        
        int sum=0;
        for(auto x:candy)
            sum+=x;
        
        return sum;
    }
};