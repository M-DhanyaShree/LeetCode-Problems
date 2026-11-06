
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int,int>> q;
        vector<int> count(n+1,0);
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++) {
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int active=0,left=0,right=0;
        for(auto query:q) {
            int t=query.first,idx=query.second,start=t-x;
            while(right<logs.size() && logs[right][1]<=t) {
                int server=logs[right][0];
                if(count[server]==0) active++;
                count[server]++;
                right++;
            }
            while(left<right && logs[left][1]<start) {
                int server=logs[left][0];
                count[server]--;
                if(count[server]==0) active--;
                left++;
            }
            ans[idx]=n-active;
        }
        return ans;
    }
};
