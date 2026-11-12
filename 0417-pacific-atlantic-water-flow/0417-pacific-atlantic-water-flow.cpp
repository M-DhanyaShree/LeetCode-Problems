class Solution {
    void bfs(vector<vector<int>>& heights,vector<vector<int>>& visited,queue<pair<int,int>>& q) {
        int m=heights.size(),n=heights[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()) {
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x=r+dx[i],y=c+dy[i];
                if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && heights[x][y]>=heights[r][c]) {
                    visited[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> p(m,vector<int>(n,0)),a(m,vector<int>(n,0));
        queue<pair<int,int>> pq,aq;
        vector<vector<int>> ans;
        int i,j;
        for(i=0;i<m;i++) {
            pq.push({i,0});
            p[i][0]=1;
            aq.push({i,n-1});
            a[i][n-1]=1;
        }
        for(i=0;i<n;i++) {
            pq.push({0,i});
            p[0][i]=1;
            aq.push({m-1,i});
            a[m-1][i]=1;
        }
        bfs(heights,p,pq);
        bfs(heights,a,aq);
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(p[i][j]==1 && a[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};