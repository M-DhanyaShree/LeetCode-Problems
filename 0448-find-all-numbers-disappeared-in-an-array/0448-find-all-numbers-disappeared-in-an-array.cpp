class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i,idx;
        vector<int> ans;
        for(i=0;i<nums.size();i++) {
            idx=abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]*=(-1);
        }
        for(i=0;i<nums.size();i++) {
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};