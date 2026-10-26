class Solution {
public:
    long long dfs(vector<vector<int>>& grid,int r,int c) {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]<=0) return 0;
        long long sum=grid[r][c];
        grid[r][c]=-1;
        sum+=dfs(grid,r,c+1);
        sum+=dfs(grid,r,c-1);
        sum+=dfs(grid,r-1,c);
        sum+=dfs(grid,r+1,c);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int i,j,ans=0;
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]>0) {
                    long long sum=dfs(grid,i,j);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};