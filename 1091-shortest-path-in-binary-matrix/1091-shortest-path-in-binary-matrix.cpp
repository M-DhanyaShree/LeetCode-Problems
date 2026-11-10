class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        int dx[]={1,1,1,-1,-1,-1,0,0};
        int dy[]={1,-1,0,1,-1,0,1,-1};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=1;
        while(!q.empty()) {
            int s=q.size();
            for(int i=0;i<s;i++) {
                auto [r,c]=q.front();
                q.pop();
                if(r==n-1 && c==n-1) return ans;
                for(int j=0;j<8;j++) {
                    int x=r+dx[j],y=c+dy[j];
                    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0) {
                        grid[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};