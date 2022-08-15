class Solution {
public:
    int romanToInt(string s) 
    {
        int n=s.size();
        stack<char> st;
        
        for(int i=0; i<n; i++)
            st.push(s[i]);
        
        int res=0,size=st.size(), i=0;
        while(i<size)
        {
            char x=st.top();
            // cout << x ;
            st.pop();
            
            if(x=='I')
                res+=1;
            else if(x=='V')
            {
                if(i+1!=size)
                {
                    if(st.top()=='I')
                    {
                        st.pop();
                        res=res+4;
                        size--;
                    }
                    else
                        res+=5;
                }
                else
                {
                    res+=5;
                }
            }
            else if(x=='X')
            {
                if(i+1!=size)
                {
                    if(st.top()=='I')
                    {
                        st.pop();
                        res=res+9;
                        size--;
                    }
                    else
                        res+=10;
                }
                else
                {
                    res+=10;
                }
            }
            else if(x=='L')
            {
                if(i+1!=size)
                {
                    if(st.top()=='X')
                    {
                        st.pop();
                        res=res+40;
                        size--;
                    }
                    else
                        res+=50;
                }
                else
                    res+=50;
            }
            else if(x=='C')
            {
                if(i+1!=size)
                {
                    if(st.top()=='X')
                    {
                        st.pop();
                        res=res+90;
                        size--;
                    }
                    else
                        res+=100;
                }
                else
                    res+=100;
            }
            else if(x=='D')
            {
                if(i+1!=size)
                {
                    if(st.top()=='C')
                    {
                        st.pop();
                        res=res+400;
                        size--;
                    }
                    else
                        res+=500;
                }
                else
                    res+=500;
            }
            else if(x=='M')
            {
                if(i+1!=size)
                {
                    if(st.top()=='C')
                    {
                        st.pop();
                        res=res+900;
                        size--;
                    }
                    else
                        res+=1000;
                }
                else
                    res+=1000;
            }
            
            i++;
        }
        
        
        return res;
    }
};