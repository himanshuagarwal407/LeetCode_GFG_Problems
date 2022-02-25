class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        if(n!=m)
            return false;
        
        unordered_map<char, int> map;
        for(int i=0; i<n; i++)
        {
            if(map.find(s[i])==map.end())
                map.insert({s[i], 0});
            else
                map[s[i]]++;
        }
        
        unordered_map<char, int> map1;
        for(int i=0; i<n; i++)
        {
            if(map1.find(t[i])==map1.end())
                map1.insert({t[i], 0});
            else
                map1[t[i]]++;
        }
        
        if(map.size()!=map1.size())
            return false;
        
        for(auto x:map)
        {
            if(map1.find(x.first)==map1.end())
                return false;
            
            if(map1[x.first]!=x.second)
                return false;
        }
        
        return true;
    }
};