class Solution {
public:
    bool solve(unordered_map<string, int> wordCount, string s, int len)
    {
        for(int j=0; j<s.size(); j+=len)
        {
            string x = s.substr(j, len);
            if(wordCount.find(x)!=wordCount.end())
            {
                if(--wordCount[x]==-1)
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wLen=words[0].size();
        int sLen=s.size();
        int window=words.size()*wLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++)
            wordCount[words[i]]++;
        
        int i=0;
        while(i+window<=sLen)
        {
            if(solve(wordCount, s.substr(i, window), wLen))
                res.push_back(i);
            i++;
        }
        
        return res;
    }
};