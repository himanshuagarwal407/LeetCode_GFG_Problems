class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(), m=b.size();
        
        string ans="";
        int i=n-1, j=m-1;
        int carry=0;
        
        while(i>=0 && j>=0)
        {
            int x=a[i]-'0';
            int y=b[j]-'0';
            
            ans+=to_string((x+y+carry)%2);
            carry = (x+y+carry)>=2 ? 1 : 0;
            
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int x=a[i]-'0';
            ans+=to_string((x+carry)%2);
            carry = (x+carry)==2 ? 1 : 0;
            i--;
        }
        while(j>=0)
        {
            int y=b[j]-'0';
            ans+=to_string((y+carry)%2);
            carry = (y+carry)==2 ? 1 : 0;
            j--;
        }
        
        if(carry)
            ans+=to_string(carry);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};