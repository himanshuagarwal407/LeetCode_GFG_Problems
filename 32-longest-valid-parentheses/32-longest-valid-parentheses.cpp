class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        
        stack<pair<char, int>> st;
        vector<int> dp(n, 0);
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            
            if(ch==')')
            {
                if(st.empty())
                    continue;
                
                if(st.top().first=='(')
                {
                    int ind = st.top().second;
                    st.pop();
                    
                    if(ind-1>=0)
                        dp[i]=2+dp[i-1]+dp[ind-1];
                    else
                        dp[i]=2+dp[i-1];
                    
                }
            }
            else
                st.push({ch, i});
        }
        
        int maxLen=INT_MIN;
        
        for(int i=0; i<n; i++)
            maxLen=max(maxLen, dp[i]);
        
        if(maxLen==INT_MIN)
            return 0;
        return maxLen;
    }
};