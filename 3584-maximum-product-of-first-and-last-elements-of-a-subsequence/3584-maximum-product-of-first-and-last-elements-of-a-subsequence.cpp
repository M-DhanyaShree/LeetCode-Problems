class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long prod,min_n,max_n,p1,p2;
        int j,i;
        prod=LLONG_MIN;
        min_n=LLONG_MAX;max_n=LLONG_MIN;
        for(j=m-1;j<nums.size();j++) {
            i=j-m+1;
            min_n=min(min_n,(long long)nums[i]);
            max_n=max(max_n,(long long)nums[i]);
            p1=min_n*(long long)nums[j];
            p2=max_n*(long long)nums[j];
            prod=max({p1,p2,prod});
        }
        return prod;
    }
};