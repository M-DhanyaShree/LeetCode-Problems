class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid,f=-1,l=-1;
        while(low<=high) { 
            mid=low+(high-low)/2;
            if(nums[mid]==target) {
                f=mid;
                high=mid-1;
            }
            else if(target<nums[mid]) high=mid-1;
            else low=mid+1;
        }
        low=0;high=nums.size()-1;
        while(low<=high) { 
            mid=low+(high-low)/2;
            if(nums[mid]==target) {
                l=mid;
                low=mid+1;
            }
            else if(target<nums[mid]) high=mid-1;
            else low=mid+1;
        }
        return {f,l};
    }
};