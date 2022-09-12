#include<bits/stdc++.h>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        
        map<char, int> mp;
        int maxi=0;
        for(auto x:tasks)
        {
            mp[x]++;
            maxi = max(maxi, mp[x]); 
        }
        
        int cMaxi=0;
        for(auto x:mp)
            if(x.second==maxi)
                cMaxi++;
        
        int ans = 1+(n+1)*(maxi-1) + cMaxi-1;
        int size = tasks.size();
        return max(ans, size);
    }
};