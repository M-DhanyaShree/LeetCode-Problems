class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        vector<vector<int>> ans;
        int i;
        sort(intv.begin(), intv.end());
        for(i=0;i<intv.size();i++)
        {
            int st=intv[i][0],en=intv[i][1];
            while(i+1<intv.size() && intv[i+1][0]<=en) {
                en=max(en,intv[i+1][1]);
                i++;
            }
            vector<int> temp;
            temp.push_back(st);
            temp.push_back(en);
            ans.push_back(temp);
        }
        return ans;
    }
};