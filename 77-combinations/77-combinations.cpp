class Solution {
public:
    vector<vector<int>> ans;
    
    void combination(int n , int k, vector<int> v, int ind)
    {
        if(v.size()==k)
            ans.push_back(v);
        
        for(int i=ind; i<=n; i++)
        {
            v.push_back(i);
            combination(n, k, v, i+1);
            v.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        
        combination(n, k, v, 1);
        
        return ans;
    }
};