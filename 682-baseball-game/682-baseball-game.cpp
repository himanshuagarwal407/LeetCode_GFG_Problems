#include<bits/stdc++.h>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n=ops.size();
        string s1 = "C", s2 = "D", s3 = "+";
        
        for(int i=0; i<n; i++)
        {
            string s = ops[i];
            
            if(s == s1)
            {
                st.pop();
            }
            else if(s == s2)
            {
                st.push(2*st.top());
            }
            else if(s == s3)
            {
                int x=st.top();
                st.pop();
                int y = x+st.top();
                st.push(x);
                st.push(y);
            }
            else
            {
                st.push(stoi(s));
            }
            
            // if(!st.empty())
            //     cout << "top: " << st.top() << endl;
        }
        
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};