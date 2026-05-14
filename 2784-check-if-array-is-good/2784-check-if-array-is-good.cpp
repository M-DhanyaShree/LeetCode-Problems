class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int mx=*max_element(nums.begin(),nums.end());
        if(nums.size()!=mx+1) return false;
        unordered_map<int,int> mp;
        for(int i: nums)
        {
            mp[i]++;
        }
        for(int i=1;i<mx;i++)
        {
            if(mp[i]!=1) return false;
        }
        return mp[mx]==2;
    }
};