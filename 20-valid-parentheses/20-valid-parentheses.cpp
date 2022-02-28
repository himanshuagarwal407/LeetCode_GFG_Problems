class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            char c=s[i];
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else
            {
                if(st.empty())
                    return false;
                
                char top=st.top();
                if(c==')')
                {
                    if(top=='(')
                        st.pop();
                    else
                        return false;
                }
                else if(c=='}')
                {
                    if(top=='{')
                        st.pop();
                    else
                        return false;
                }
                else if(c==']')
                {
                    if(top=='[')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
    }
};