class Solution {
    struct box {
        int r,c,k;
    };
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<box> q;
        int m=grid.size(),n=grid[0].size();
        if(k>=m+n-2) return m+n-2;
        vector<vector<int>> visited(m,vector<int>(n,-1));
        int sk=k-grid[0][0],ans=0;
        if(sk<0) return -1;
        q.push({0,0,sk}); visited[0][0]=sk;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                auto [r,c,rk]=q.front();
                q.pop();
                if(r==m-1 && c==n-1) return ans;
                for(int j=0;j<4;j++) {
                    int x=r+dx[j],y=c+dy[j];
                    if(x>=0 && x<m && y>=0 && y<n) {
                        int nk=rk-grid[x][y];
                        if(nk>=0 && nk>visited[x][y]) {
                            visited[x][y]=nk;
                            q.push({x,y,nk});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};