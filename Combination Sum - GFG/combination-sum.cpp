// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    void combinationSum(vector<int> a, int n, int i, vector<int>& v, vector<vector<int>>& ans, int sum)
    {
        if(sum==0)
        {
            ans.push_back(v);
            return;
        }
        else if(sum<0)
            return ;
            
        for(int k=i; k<n; k++)
        {
            if(k>0 && a[k]==a[k-1])
                continue;
            v.push_back(a[k]);
            combinationSum(a, n, k, v, ans, sum-a[k]);
            v.pop_back();
        }
    }
    
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        
        int n=A.size();
        vector<int> v;
        vector<vector<int>> ans;
        
        combinationSum(A, n, 0, v, ans, B);
        
        return ans;
        // Your code here
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends