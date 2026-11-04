class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        vector<long long> c(n,0);
        multiset<long long> L,R;
        long long sL=0,sR=0;

        auto bal=[&]() {
            while(L.size()>(size_t)(x+1)/2) {
                auto it=prev(L.end());
                sL-=*it; sR+=*it;
                R.insert(*it); L.erase(it);
            }
            while(L.size()<(size_t)(x+1)/2 && !R.empty()) {
                auto it=R.begin();
                sL+=*it; 
                sR-=*it;
                L.insert(*it); 
                R.erase(it);
            }
        };

        auto add=[&](long long v) {
            if(L.empty()||v<=*prev(L.end())) {
                L.insert(v); sL+=v;
            }
            else {
                R.insert(v); sR+=v;
            }
            bal();
        };

        auto rem=[&](long long v) {
            auto it=L.find(v);
            if(it!=L.end()) {
                sL-=*it; L.erase(it);
            }
            else {
                it=R.find(v);
                if(it!=R.end()) {
                    sR-=*it; R.erase(it);
                }
            }
            bal();
        };

        for(int i=0;i<n;++i) {
            add(nums[i]);
            if(i>=x) rem(nums[i-x]);
            if(i>=x-1){
                long long m=*prev(L.end());
                c[i]=((long long)L.size()*m-sL)+(sR-(long long)R.size()*m);
            }
        }

        vector<vector<long long>> dp(n+1,vector<long long>(k+1,1e18));
        for(int i=0;i<=n;++i) dp[i][0]=0;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=k;++j) {
                dp[i][j]=dp[i-1][j];
                if(i>=x && dp[i-x][j-1]!=1e18) {
                    dp[i][j]=min(dp[i][j],dp[i-x][j-1]+c[i-1]);
                }
            }
        }
        return dp[n][k];
    }
};