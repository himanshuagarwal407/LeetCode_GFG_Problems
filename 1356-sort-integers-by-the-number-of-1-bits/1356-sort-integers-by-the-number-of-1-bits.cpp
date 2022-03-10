class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second<b.second;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        
        for(int i=0; i<arr.size(); i++)
        {
            v.push_back({arr[i], __builtin_popcount(arr[i])});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans;
        for(int i=0; i<v.size(); i++)
            ans.push_back(v[i].first);
        
        return ans;
    }
};