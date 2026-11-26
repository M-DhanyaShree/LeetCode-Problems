class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q(nums.begin(),nums.end());
        double sum=0,temp=0,x;
        int ans=0;
        for(int i:nums) sum+=i;
        while(!q.empty()) {
            x=q.top()/2;
            q.pop();
            temp+=x;
            ans++;
            if(temp>=sum/2) return ans;
            q.push(x);
        }
        return ans;
    }
};