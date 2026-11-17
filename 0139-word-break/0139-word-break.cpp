class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),i,j;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(i=1;i<=n;i++) {
            for(j=0;j<n;j++) {
                if(dp[j]==1 && st.count(s.substr(j,i-j))) {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};