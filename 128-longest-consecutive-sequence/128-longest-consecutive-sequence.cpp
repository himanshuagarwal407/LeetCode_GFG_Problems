class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        
        unordered_set<int> st;
        
        for(auto x:nums)
            st.insert(x);
        
        int maxLen=0;
        
        for(int x:st)
        {
            if(st.find(x-1)==st.end())
            {
                int currx=x;
                int len=1;
                
                while(st.find(currx+1)!=st.end())
                {
                    currx+=1;
                    len+=1;
                }
                
                maxLen=max(len, maxLen);
            }
        }
        
        return maxLen;
    }
};