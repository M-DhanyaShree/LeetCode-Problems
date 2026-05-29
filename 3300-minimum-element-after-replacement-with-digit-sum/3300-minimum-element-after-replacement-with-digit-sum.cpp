class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        int i,n,sum,mini=INT_MAX;
        for(i=0;i<nums.size();i++)
        {
            n=nums[i];
            sum=0;
            while(n>0)
            {
                sum+=n%10;
                n/=10;
            }
            mini=min(mini, sum);
        }
        return mini;
    }
};