class Solution {
    bool backtrack(vector<vector<char>>& board,string word,int r,int c,int idx) {
        if(idx==word.size()) return true;
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[idx]) return false;
        char temp=board[r][c];
        board[r][c]='#';
        bool ans=backtrack(board,word,r-1,c,idx+1) || backtrack(board,word,r+1,c,idx+1) || backtrack(board,word,r,c+1,idx+1) || backtrack(board,word,r,c-1,idx+1);
        board[r][c]=temp;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        for(i=0;i<board.size();i++) {
            for(j=0;j<board[i].size();j++) {
                if(backtrack(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};