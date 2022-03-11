class Solution {
public:
    
    vector<vector<int>> ans;
    
    void helper(int n, int k, vector<int> temp, int index)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index; i<=n; i++)
        {
            temp.push_back(i);
            helper(n, k, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        helper(n, k, temp, 1);
		
        return ans;
    }
};