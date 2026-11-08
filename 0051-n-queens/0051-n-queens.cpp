class Solution {
    bool valid(vector<string>& board,int r,int c,int n) {
        int i,j;
        for(i=0;i<r;i++) {
            if(board[i][c]=='Q') return false;
        }
        for(i=r-1,j=c-1;i>=0 && j>=0;i--,j--) {
            if(board[i][j]=='Q') return false;
        }
        for(i=r-1,j=c+1;i>=0 && j<n;i--,j++) {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans,int r,vector<string>& board,int n) {
        if(r==n) {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++) {
            if(valid(board,r,i,n)) {
                board[r][i]='Q';
                backtrack(ans,r+1,board,n);
                board[r][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        backtrack(ans,0,board,n);
        return ans;
    }
};