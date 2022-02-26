class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        
        
        int maxSize=0;
        
        for(int i=0; i<n; i++)
        {
            unordered_map<char, int> map;
            int j=i, size=1;
            while(j<n)
            {
                if(map.find(s[j])==map.end())
                    map.insert({s[j],0});
                else
                    break;
                j++;
            }
            size=j-i;
            maxSize=(maxSize<size)?size:maxSize;
        }
        
        return maxSize;
    }
};