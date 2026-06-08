class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr=false,fc=false;
        int i,j,m=matrix.size(),n=matrix[0].size();
        for(i=0;i<m;i++) {
            if(matrix[i][0]==0) {fr=true; break;}
        }
        for(i=0;i<n;i++) {
            if(matrix[0][i]==0) {fc=true; break;}
        }
        for(i=1;i<m;i++) {
            for(j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(i=1;i<m;i++) {
            for(j=1;j<n;j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(fr) {
            for(i=0;i<m;i++) matrix[i][0]=0;
        }
        if(fc) {
            for(i=0;i<n;i++) matrix[0][i]=0;
        }
    }
};