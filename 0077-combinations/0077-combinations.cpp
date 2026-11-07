class Solution {
    void backtrack(vector<vector<int>>& ans,vector<int>& temp,int k,int n,int curr) {
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<=n;i++) {
            temp.push_back(i);
            backtrack(ans,temp,k,n,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,temp,k,n,1);
        return ans;
    }
};