class Solution {
    void dfs(vector<vector<int>>& graph,int st,vector<int>& vis) {
        vis[st]=1;
        for(int i=0;i<graph.size();i++) {
            if(graph[st][i]==1 && !vis[i]) dfs(graph,i,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0,i;
        vector<int> vis(n,0);
        for(i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(isConnected,i,vis);
            }
        }
        return cnt;
    }
};