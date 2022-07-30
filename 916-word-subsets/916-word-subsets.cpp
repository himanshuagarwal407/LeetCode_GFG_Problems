class Solution {
public:
    vector<int> getFreq(string s)
    {
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++)
            freq[s[i]-'a']++;
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> maxF(26, 0);
        
        for(auto x:words2)
        {
            vector<int> freq = getFreq(x);
            
            for(int i=0; i<26; i++)
                maxF[i] = max(maxF[i], freq[i]);
        }
        
        for(auto x:words1)
        {
            vector<int> freq = getFreq(x);
            
            bool flag=1;
            for(int i=0; i<26; i++)
            {
                if(freq[i]<maxF[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans.push_back(x);
        }
        
        return ans;
    }
};