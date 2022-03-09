class Solution {
public:
    string toLowerCase(string s) {
        string st="";
        for(int i=0; i<s.size(); i++)
            st+=tolower(s[i]);
        
        return st;
    }
};