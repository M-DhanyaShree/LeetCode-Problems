class Solution {
public:
    int leastInterval(vector<char>& tasks,int n) {
        vector<int> f(26,0);
        for(char c:tasks) f[c-'A']++;
        priority_queue<int> pq;
        for(int x:f) {
            if(x>0) pq.push(x);
        }
        queue<pair<int,int>> q;
        int t=0;
        while(!pq.empty() || !q.empty()) {
            t++;
            if(!pq.empty()) {
                int cnt=pq.top()-1;
                pq.pop();
                if(cnt>0) q.push({cnt,t+n});
            }
            if(!q.empty() && q.front().second==t) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};