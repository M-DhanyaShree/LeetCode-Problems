class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& res,int target,int k,int st) {
        if(res.size()==k) {
            if(target==0) ans.push_back(res);
            return;
        }
        for(int i=st;i<=9;i++) {
            if(i>target) break;;
            res.push_back(i);
            backtrack(res,target-i,k,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> res;
        backtrack(res,n,k,1);
        return ans;
    }
};