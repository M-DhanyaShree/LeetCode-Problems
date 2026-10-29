class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9]={0},c[9]={0},b[9]={0},i,j,v,m,k;
        for(i=0;i<9;i++) {
            for(j=0;j<9;j++) {
                if(board[i][j]=='.') continue;
                v=board[i][j]-'0';
                m=1<<v;
                k=(i/3)*3+j/3;
                if((r[i]&m)||(c[j]&m)||(b[k]&m)) return false;
                r[i]|=m;
                c[j]|=m;
                b[k]|=m;
            }
        }
        return true;
    }
};