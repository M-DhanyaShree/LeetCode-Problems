class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> frnds;
        vector<int> ans;
        frnds.insert(friends.begin(), friends.end());
        for(int i:order) {
            if(frnds.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};