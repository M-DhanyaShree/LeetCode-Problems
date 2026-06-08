class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i,n=nums.size(),piv=-1;
        for(i=n-1;i>0;i--) {
            if(nums[i]>nums[i-1]) {
                piv=i-1; break;
            }
        }
        if(piv==-1) {
            reverse(nums.begin(),nums.end()); return;
        }
        for(i=n-1;i>=piv;i--) {
            if(nums[i]>nums[piv]) {
                swap(nums[piv],nums[i]); break;
            }
        }
        reverse(nums.begin()+piv+1,nums.end());
    }
};