class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(),stones.end());
        int x,y;
        while(!q.empty()) {
            if(q.size()==1) return q.top();
            x=q.top(); q.pop();
            y=q.top(); q.pop();
            if(x!=y) q.push(x-y);
        }
        return 0;
    }
};