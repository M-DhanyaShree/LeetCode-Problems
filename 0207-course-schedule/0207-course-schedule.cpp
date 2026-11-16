class Solution {
    bool dfs(vector<vector<int>>& preq,vector<int>& vis,int u) {
        vis[u]=1;
        for(int v:preq[u]) {
            if(vis[v]==1) return 1;
            if(vis[v]==0 && dfs(preq,vis,v)) return true;
        }
        vis[u]=2;
        return false;
    } 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i;
        vector<vector<int>> preq(numCourses);
        vector<int> vis(numCourses,0);
        for(auto& p:prerequisites) preq[p[1]].push_back(p[0]);
        for(i=0;i<numCourses;i++) {
            if(vis[i]==0 && dfs(preq,vis,i)) return false;
        }
        return true;
    }
};