class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int i,j,ans=0,k,cnt=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
                else if(grid[i][j]==1) cnt++;
            }
        }
        while(!q.empty() && cnt>0) {
            int n=q.size();
            for(int a=0;a<n;a++) {
                auto [i,j]=q.front();
                q.pop();
                for(k=0;k<4;k++) {
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==1) {
                        grid[x][y]=2;
                        cnt--;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        return cnt==0?ans:-1;
    }
};