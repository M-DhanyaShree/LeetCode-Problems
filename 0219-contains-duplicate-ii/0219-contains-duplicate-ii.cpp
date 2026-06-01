class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int l=0,r=0;
        unordered_set<int> s;
        for(r=0;r<nums.size();r++)
        {
            while((r-l)>k)
            {
                s.erase(nums[l]);
                l++;
            }
            if(s.count(nums[r])) return true;
            s.insert(nums[r]);
        }
        return false;
    }
};