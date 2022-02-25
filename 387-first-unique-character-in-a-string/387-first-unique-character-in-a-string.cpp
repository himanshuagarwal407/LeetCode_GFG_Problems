class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int n=s.size();
        
        for(int i=0; i<n; i++)
        {
            if(map.find(s[i])!=map.end())
            {
                map[s[i]]++;
            }
            else
                map.insert({s[i],0});
            
        }
        
        for(int i=0; i<n; i++)
        {
            if(map[s[i]]==0)
                return i;
        }
        
        return -1;
    }
};