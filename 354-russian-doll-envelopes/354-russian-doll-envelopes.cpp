#include<bits/stdc++.h>

class Solution {
public:
    static bool cmpr(vector<int>& a, vector<int>& b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        
        return a[1]>b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& en) {
        int n=en.size();
        
        sort(en.begin(), en.end(), cmpr);
        
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int x=en[i][1];
            int y=lower_bound(v.begin(), v.end(), x)-v.begin();
            
            if(y>=v.size())
                v.push_back(x);
            else
                v[y]=x;
        }
        
        return v.size();
    }
};