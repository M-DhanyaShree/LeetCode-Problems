class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        int i;  
        for(i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end() && mp[rem]!=i) 
            {
                ans.push_back(i);
                ans.push_back(mp[rem]);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};