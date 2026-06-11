class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i,j;
        vector<vector<int>> ans={{1}};
        if(numRows>1) ans.push_back({1,1});
        for(i=2;i<numRows;i++)
        {
            vector<int> temp(i+1,1);
            for(j=1;j<i;j++) temp[j]=ans[i-1][j-1]+ans[i-1][j];
            ans.push_back(temp);
        }
        return ans;
    }
};