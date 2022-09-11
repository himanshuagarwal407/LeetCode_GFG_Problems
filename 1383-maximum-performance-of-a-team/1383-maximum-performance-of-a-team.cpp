class Solution {
    int mod=1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& effic, int k) {
        vector<pair<int, int>> eng;
        
        for(int i=0; i<n; i++)
            eng.push_back({effic[i], speed[i]});
        
        sort(eng.rbegin(), eng.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long tSpeed=0, ans=0;
        
        for(int i=0; i<n; i++)
        {
            int cSpeed = eng[i].second;
            int cEffic = eng[i].first;
            
            if(pq.size()==k)
            {
                tSpeed -= pq.top();
                pq.pop();
            }
            
            pq.push(cSpeed);
            tSpeed += cSpeed;
            
            ans = max(ans, tSpeed*cEffic);
        }
        
        return ans%mod;
    }
};