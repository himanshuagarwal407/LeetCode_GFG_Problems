// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(mp.find(a[i])==mp.end())
                mp[a[i]]=1;
            else
                mp[a[i]]++;
        }
        
        int i=0;
        for(; i<mp[0]; i++)
            a[i] = 0;
            
        for(; i<(mp[1]+mp[0]); i++)
            a[i] = 1;
            
        for(; i<n; i++)
            a[i] = 2;
        // coode here 
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends