class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0,x=1000;
        while(n>=x) {
            ans+=(n-x+1);
            if(x>LLONG_MAX/1000) break;
            x*=1000;
        }
        return ans;
    }
};