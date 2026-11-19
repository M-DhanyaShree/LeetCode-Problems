class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,j,n=nums.size();
        vector<bool> dp(n,false);
        dp[0]=true;
        for(i=1;i<n;i++) {
            for(j=i-1;j>=0;j--) {
                if(dp[j] && j+nums[j]>=i) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};