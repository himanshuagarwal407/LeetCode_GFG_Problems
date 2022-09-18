class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<>());
        sort(s.begin(), s.end(), greater<>());
        
        int i=0, j=0;
        int n=g.size(), m=s.size();
        int count=0;
        
        while(i<n && j<m)
        {
            if(g[i]<=s[j])
            {
                count++;
                i++;
                j++;
            }
            else
                i++;
        }
        
        return count;
    }
};