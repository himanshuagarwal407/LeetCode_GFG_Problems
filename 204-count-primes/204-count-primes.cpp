class Solution {
public:
    int isPrime(int n)
    {
        for(int i=2; i<=n/2; i++)
            if(n%i==0)
                return 0;
        
        return 1;
    }
    
    int countPrimes(int n) {
        vector<int> isp(n,1);
        
        for(int i=2; i*i<n; i++)
        {
            if(!isPrime(i))
                continue;
            for(int j=i*i; j<n; j+=i)
                isp[j]=0;
        }
        
        int count=0;
        for(int i=2; i<n; i++)
            if(isp[i]==1)
                count++;
        
        return count;
    }
};