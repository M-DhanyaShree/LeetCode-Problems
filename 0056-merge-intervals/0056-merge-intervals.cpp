class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i;
        sort(intv.begin(), intv.end());
        for(i=0;i<intv.size();i++)
        {
            int start = intv[i][0];
            int end = intv[i][1];
            while(i+1 < intv.size() && intv[i+1][0] <= end)
            {
                end = max(end, intv[i+1][1]);
                i++;
            }
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        return ans;
    }
};