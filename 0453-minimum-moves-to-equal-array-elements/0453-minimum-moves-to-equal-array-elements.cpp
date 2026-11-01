class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x=INT_MAX,i,sum=0;
        for(i=0;i<nums.size();i++) x=min(x,nums[i]);
        for(i=0;i<nums.size();i++) sum+=(nums[i]-x);
        return sum;
    }
};