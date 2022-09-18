class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int ans=0;
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && h[i]>h[st.top()])
            {
                int top = st.top();
                st.pop();
                
                if(st.empty())
                    break;
                int dis = i-st.top()-1;
                int hei = min(h[i], h[st.top()])-h[top];
                
                ans += dis*hei;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};