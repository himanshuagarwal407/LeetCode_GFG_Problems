class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), l=0, h=0;
        unordered_map<char, int> map;
        int ans=0;
        
        while(l<=h && h<n)
        {
            map[s[h]]++;
            
            while(map[s[h]]>1)
            {
                map[s[l]]--;
                l++;
            }
            
            ans = max(ans, h-l+1);
            h++;
        }
        
        return ans;
        
    }
};