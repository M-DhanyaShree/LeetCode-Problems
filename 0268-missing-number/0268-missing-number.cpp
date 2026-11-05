class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),sum=0,tot;
        tot=(n*(n+1))/2;
        for(int i:nums) sum+=i;
        return tot-sum;
    }
};