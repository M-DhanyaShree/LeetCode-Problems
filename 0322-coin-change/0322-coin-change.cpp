class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i;
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(i=1;i<=amount;i++) {
            for(int c:coins) {
                if(c<=i) dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};