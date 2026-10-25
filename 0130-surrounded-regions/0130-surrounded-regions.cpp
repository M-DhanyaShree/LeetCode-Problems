class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c) {
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()) return;
        if(board[r][c]!='O') return;
        board[r][c]='E';
        dfs(board,r,c-1);
        dfs(board,r,c+1);
        dfs(board,r-1,c);
        dfs(board,r+1,c);
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size(),i,j;
        for(i=0;i<c;i++) {
            if(board[0][i]=='O') dfs(board,0,i);
        if(board[r-1][i]=='O') dfs(board,r-1,i);
        }
        for(j=0;j<r;j++) {
            if(board[j][0]=='O') dfs(board,j,0);
            if(board[j][c-1]=='O') dfs(board,j,c-1);
        }
        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='E') board[i][j]='O';
            }
        }
    }
};