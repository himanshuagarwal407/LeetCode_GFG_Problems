// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int sum=0, maxLen=0, len=0;
        
        map<int, int> mp;
        mp[0]=-1;
        
        for(int i=0; i<n; i++)
        {
            sum+=A[i];
            
            if(mp.find(sum)!=mp.end())
            {
                len += i-mp[sum];
                maxLen=max(len, maxLen);
                len=0;
            }
            else
                mp[sum]=i;
        }
        
        return maxLen;
        // Your code here
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends