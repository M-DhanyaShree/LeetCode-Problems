class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suff(n);
        int i;
        suff[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--) suff[i]=min(nums[i],suff[i+1]);
        int pref=nums[0];
        for(i=0;i<n;i++) {
            pref=max(pref,nums[i]);
            if(pref-suff[i]<=k) return i;
        }
        return -1;
    }
};