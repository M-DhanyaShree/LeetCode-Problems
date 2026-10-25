class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int r,int c) {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()) return false;
        if(grid[r][c]==1) return 1;
        grid[r][c]=1;
        bool left=dfs(grid,r,c-1);
        bool right=dfs(grid,r,c+1);
        bool up=dfs(grid,r-1,c);
        bool down=dfs(grid,r+1,c);
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),i,j,ans;
        for(i=0;i<c;i++) {
            if(grid[0][i]==0) dfs(grid,0,i);
            if(grid[r-1][i]==0) dfs(grid,r-1,i);
        }
        for(j=0;j<r;j++) {
            if(grid[j][0]==0) dfs(grid,j,0);
            if(grid[j][c-1]==0) dfs(grid,j,c-1);
        }
        ans=0;
        for(i=1;i<r-1;i++) {
            for(j=1;j<c-1;j++) {
                if(grid[i][j]==0) {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};