class Solution {
public:
    string reverseWords(string str) {
        vector<string> v;
    
        istringstream ss(str);
        string word;

        while(ss>>word)
            v.push_back(word);

        string ans="";
        for(int i=v.size()-1; i>0; i--)
        {
            ans+=v[i];
            ans+=" ";
        }
        ans+=v[0];

        return ans;
    }
};