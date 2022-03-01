class Solution {
public:
    string reverseWords(string s) {
        string st="";
        stack<char> ch;
        
        for(auto c : s)
        {
            
            if(c!=' ')
                ch.push(c);
            else
            {
                while(!ch.empty())
                {
                    st+=ch.top();
                    ch.pop();
                }
                st+=' ';
                    
            }
                
        }
        while(!ch.empty())
        {
            st+=ch.top();
            ch.pop();
        }
        
        return st;
    }
};