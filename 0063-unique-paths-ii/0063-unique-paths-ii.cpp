class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        int i,j;
        if(m!=0 && n!=0 && obstacleGrid[0][0]==1) return 0;
        for(i=0;i<m;i++) {
            if(obstacleGrid[i][0]==1) break;
            else dp[i][0]=1;
        }
        for(j=0;j<n;j++) {
            if(obstacleGrid[0][j]==1) break;
            else dp[0][j]=1;
        }
        for(i=1;i<m;i++) {
            for(j=1;j<n;j++) {
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};