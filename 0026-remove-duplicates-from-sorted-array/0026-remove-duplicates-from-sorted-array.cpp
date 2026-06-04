class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int a,b=1;
        for(a=1;a<nums.size();a++)
        {
            if(nums[a]!=nums[b-1]) 
            {
                nums[b]=nums[a];
                b++;
            }
        }
        return b;
    }
};