class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int i,n=nums.size();
        vector<int> temp(n);
        k%=n;
        for(i=0;i<nums.size();i++)
        {
            temp[(i+k)%n]=nums[i];
        }    
        nums=temp;
    }
};