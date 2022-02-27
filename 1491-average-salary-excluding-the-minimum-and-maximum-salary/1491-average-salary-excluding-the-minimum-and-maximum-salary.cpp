class Solution {
public:
    double average(vector<int>& salary) {
        int min=INT_MAX;
        int max=INT_MIN;
        int sum=0;
        
        for(int i=0; i<salary.size(); i++)
        {
            sum+=salary[i];
            min=(salary[i]<min)?salary[i]:min;
            max=(salary[i]>max)?salary[i]:max;
        }
        
        sum=sum-(max+min);
        
        return (double)sum/(salary.size()-2);
    }
};