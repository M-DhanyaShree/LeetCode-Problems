class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& memo) {
        if(i==j) return nums[i];
        if(memo[i][j]!=INT_MIN) return memo[i][j];
        int left=nums[i]-solve(i+1,j,nums,memo);
        int right=nums[j]-solve(i,j-1,nums,memo);
        return memo[i][j]=max(left,right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n,vector<int>(n,INT_MIN));
        return solve(0,n-1,nums,memo)>=0;
    }
};