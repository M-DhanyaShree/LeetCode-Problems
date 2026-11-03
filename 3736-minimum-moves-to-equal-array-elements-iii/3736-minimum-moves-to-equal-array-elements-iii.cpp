class Solution {
public:
    int minMoves(vector<int>& nums) {
        int big=0,i,sum=0;
        for(i=0;i<nums.size();i++) big=max(big,nums[i]);
        for(i=0;i<nums.size();i++) sum+=(big-nums[i]);
        return sum;
    }
};