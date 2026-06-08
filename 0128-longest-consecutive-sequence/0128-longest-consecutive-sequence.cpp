class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> freq;
       int i,cnt=0,curr,big=0;
       for(i=0;i<nums.size();i++) {
            freq.insert(nums[i]);
       }
       for(int x: freq) {
            if(freq.find(x-1)==freq.end()) {
                curr=x;cnt=1;
                while(freq.find(curr+1)!=freq.end()) {
                    curr++;cnt++;
                }
                big=max(big,cnt);
            }
       }
       return big;
    }
};