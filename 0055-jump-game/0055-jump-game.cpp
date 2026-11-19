class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,mr=0,n=nums.size();
        for(i=0;i<n;i++) {
            if(i>mr) return false;
            mr=max(mr,i+nums[i]);
            if(mr>=n-1) return true;
        }
        return true;
    }
};