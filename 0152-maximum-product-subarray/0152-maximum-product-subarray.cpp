class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],maxp=1,minp=1;
        for(int i:nums) {
            if(i<0) swap(maxp,minp);
            maxp=max(i,i*maxp);
            minp=min(i,i*minp);
            ans=max(maxp,ans);
        }
        return ans;
    }
};