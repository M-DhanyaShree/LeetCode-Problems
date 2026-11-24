class Solution {
public:
    int maxLength(vector<int>& nums) {
        int l=0,r,ans=2,n=nums.size();
        long long prod=1;
        for(r=0;r<n;r++) {
            while(gcd(prod,(long long)nums[r])>1) {
                prod/=nums[l];
                l++;
            }
            prod*=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};