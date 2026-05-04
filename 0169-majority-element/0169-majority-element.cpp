class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int cnt=0,e=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0) {cnt+=1;e=nums[i];}
            else if(nums[i]!=e) cnt-=1;
            else cnt+=1;
        }    
        return e;
    }
};