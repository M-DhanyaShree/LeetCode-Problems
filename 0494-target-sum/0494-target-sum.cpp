class Solution {
    int ans=0;
    void backtrack(vector<int>& nums,int t,int curr,int i) {
        if(i==nums.size()) {
            if(curr==t) ans++;
            return;
        }
        backtrack(nums,t,curr-nums[i],i+1);
        backtrack(nums,t,curr+nums[i],i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
          backtrack(nums,target,0,0);
          return ans;
    }
};