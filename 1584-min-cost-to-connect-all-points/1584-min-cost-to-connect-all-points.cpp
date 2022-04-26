class Solution {
public:
    //Krushkal's Algorithm    
    
    int parent[1001];
    
    int find(int x)
    {
        if(parent[x]<0)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int a, int b)
    {
        parent[a]=b;
    }
    
    int minCostConnectPoints(vector<vector<int>>& v) {
        int n=v.size();
        if(n==1)
            return 0;
        
        for(int i=0; i<n; i++)  
            parent[i]=-1;
        
        vector<pair<int, pair<int, int>>> adj;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int cost = abs(v[i][0]-v[j][0]) + abs(v[i][1]-v[j][1]);
                adj.push_back({cost, {i,j}});
            }
        }
        
        sort(adj.begin(), adj.end());
        
        int res=0;
        for(int i=0; i<adj.size(); i++)
        {
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second);
            
            if(a!=b)
            {
                res+=adj[i].first;
                Union(a, b);
            }
        }
        
        return res;
    }
};