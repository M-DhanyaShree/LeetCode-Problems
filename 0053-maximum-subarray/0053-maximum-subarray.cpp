class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0,big=INT_MIN,i;
        for(i=0;i<nums.size();i++)
        {
            sum=max(nums[i],sum+nums[i]);
            big=max(big,sum);
        }
        return big;
    }
};