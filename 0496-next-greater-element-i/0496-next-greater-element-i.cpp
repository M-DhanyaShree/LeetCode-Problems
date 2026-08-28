class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> ans;
        for(int i : nums2) {
            while(!st.empty() && st.top()<i) {
                mp[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};