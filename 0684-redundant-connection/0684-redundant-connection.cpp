class Solution {
    int find(vector<int> p,int x) {
        if(p[x]==x) return x;
        return p[x]=find(p,p[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size(),i,u,v;
        vector<int> p(n+1);  
        for(i=0;i<=n;i++) p[i]=i;
        for(auto& x:edges) {
            u=find(p,x[0]);
            v=find(p,x[1]);
            if(u==v) return x;
            p[u]=v;
        }
        return {};
    }
};