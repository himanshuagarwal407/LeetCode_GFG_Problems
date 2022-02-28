class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, pro=1;
        
        while(n)
        {
            int m=n%10;
            sum+=m;
            pro*=m;
            n/=10;
        }
        
        return pro-sum;
    }
};