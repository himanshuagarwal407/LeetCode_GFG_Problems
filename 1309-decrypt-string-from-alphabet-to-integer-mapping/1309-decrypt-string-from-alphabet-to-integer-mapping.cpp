class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        
        int n=s.size();
        vector<char> v1;
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!='#')
            {
                int ind = s[i]-'0';
                v1.push_back(v[ind-1]);
            }
            else
            {
                i=i-2;
                int ind=s[i]-'0';
                ind = ind*10 + (s[i+1]-'0');
                
                v1.push_back(v[ind-1]);
            }
        }
        
        string res="";
        for(int i=v1.size()-1; i>=0; i--)
            res+=v1[i];
        
        return res;
    }
};