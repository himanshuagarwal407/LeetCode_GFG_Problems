class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> v;
        
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=1;
            else
                mp[nums[i]]++;
        }
        
        for(auto x:mp)
            pq.push({x.second, x.first});
        
        while(k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};