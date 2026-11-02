class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,i,med,n;
        n=nums.size();
        med=nums[n/2];
        for(i=0;i<n;i++) sum+=(abs(nums[i]-med));
        return sum;
    }
};