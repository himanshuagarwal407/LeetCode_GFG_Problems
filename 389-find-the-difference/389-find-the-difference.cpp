class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> map;
        for(int i=0; i<s.size(); i++)
        {
            if(map.find(s[i])!=map.end())
                map[s[i]]++;
            else
                map[s[i]]=1;
        }
        
        char c=t[0];
        for(int i=0; i<t.size(); i++)
        {
            if(map.find(t[i])==map.end() || map[t[i]]==0)
                return t[i];
            else
                map[t[i]]--;
        }
        
        return c;
    }
};