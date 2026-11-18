class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),i,j,ans=1;
        vector<int> dp(n,1);
        for(i=1;i<n;i++) {
            for(j=0;j<i;j++) {
                if(nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};