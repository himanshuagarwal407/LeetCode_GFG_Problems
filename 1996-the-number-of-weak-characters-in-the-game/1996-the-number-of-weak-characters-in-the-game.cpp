#include<bits/stdc++.h>
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n=prop.size();
        
        sort(prop.begin(), prop.end(), cmp);
        
        int maxDef=0, ans=0;
        for(auto x:prop)
        {
            if(x[1]<maxDef)
                ans++;
            else
                maxDef=x[1];
        }
        
        return ans;
    }
};