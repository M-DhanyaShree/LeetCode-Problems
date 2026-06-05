class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int i,big=0,cnt=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==1) cnt++;
            else
            {
                big=max(big,cnt);
                cnt=0;
            }
        }    
        big=max(big,cnt);
        return big;
    }
};