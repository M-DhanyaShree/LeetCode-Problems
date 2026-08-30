class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i,big=0,small=0;
        for(i=1;i<nums.size();i++) {
            big=(nums[big]>nums[i])?big:i;
            small=(nums[small]<nums[i])?small:i;
        }
        int f,s,n=nums.size();
        f=min(big,small);
        s=max(big,small);
        int a=(f+1)+(n-s);
        int b=(n-f);
        int c=(s)+1;
        return min(a,min(b,c));
    }
};