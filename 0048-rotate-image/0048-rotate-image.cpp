class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,x,y;
        for(i=0;i<matrix.size();i++)
        {
            for(j=i+1;j<matrix[i].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
            for(x=0,y=matrix[i].size()-1;x<matrix[i].size()/2;x++,y--)
            {
                swap(matrix[i][x],matrix[i][y]);
            }
        }
    }
};