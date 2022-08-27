class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int res=INT_MIN;
        
        for(int i=0; i<m; i++)
        {
            vector<int> sum(n, 0);
            for(int j=i; j<m; j++)
            {
                for(int k=0; k<n; k++)
                    sum[k]+=matrix[k][j];
                
                set<int> set={0};
                int currSum=0;
                
                for(auto x:sum)
                {
                    currSum+=x;
                    auto it=set.lower_bound(currSum-k);
                    if(it!=set.end())
                        res = max(res, currSum-*it);
                    
                    set.insert(currSum);
                }
            }
        }
        
        return res;
    }
};