class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,d,tot=0,cur=0,st=0;
        for(i=0;i<gas.size();i++) {
            d=gas[i]-cost[i];
            tot+=d;
            cur+=d;
            if(cur<0) {
                cur=0;
                st=i+1;
            }
        }
        return tot<0?-1:st;
    }
};