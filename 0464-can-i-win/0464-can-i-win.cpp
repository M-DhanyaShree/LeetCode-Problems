class Solution {
    bool solve(int mask,int rt,int n,vector<int>&dp) {
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<n;i++) {
            if((mask & (1<<i))==0) {
                int temp=i+1;
                if(temp>=rt || !solve(mask|(1<<i),rt-temp,n,dp)) {
                    return dp[mask]=1;
                }
            }
        }
        return dp[mask]=0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0) return true;
        int sum=maxChoosableInteger*(maxChoosableInteger+1)/2;
        if(sum<desiredTotal) return false;
        vector<int> dp(1<<maxChoosableInteger,-1);
        return solve(0,desiredTotal,maxChoosableInteger,dp);
    }
};