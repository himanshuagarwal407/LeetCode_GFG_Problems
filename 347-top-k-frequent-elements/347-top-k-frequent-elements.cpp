#include<bits/stdc++.h>

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second<b.second;
    }
    
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=1;
            else
                mp[nums[i]]++;
        }
        
        vector<pair<int,int>> v;
        for(auto i:mp)
            v.push_back(i);
        
        sort(v.begin(), v.end(), cmp);
        
        int j=v.size()-1;
        vector<int> ans;
        while(k)
        {   
            ans.push_back(v[j].first);
            k--;
            j--;
        }
        return ans;
            
    }
};