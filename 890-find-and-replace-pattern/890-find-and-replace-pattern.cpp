class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=pattern.size();
        int m=words.size();
        
        vector<string> ans;
        for(int i=0; i<m; i++)
        {
            string s=words[i];
            int a=s.size();
            if(a!=n)
                continue;
            
            unordered_map<char, char> mp;
            unordered_map<char, char> mp2;
            int flag=1;
            for(int j=0; j<a; j++)
            {
                char c=pattern[j];
                if(mp.find(c)==mp.end() && mp2.find(s[j])==mp2.end())
                {
                    mp[c]=s[j];
                    mp2[s[j]]=c;
                }
                else if(mp.find(c)==mp.end() || mp2.find(s[j])==mp2.end())
                {
                    flag=0;
                    continue;
                }
                else if(mp[c]!=s[j] || mp2[s[j]!=c])
                {
                    flag=0;
                    continue;
                }
            }
            if(flag==1)
                ans.push_back(s);
        }
        
        return ans;
    }
};