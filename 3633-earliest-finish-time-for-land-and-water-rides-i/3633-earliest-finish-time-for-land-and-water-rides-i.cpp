class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i=0;i<landStartTime.size();i++)
        {
            for(int j=0;j<waterStartTime.size();j++)
            {
                int lf=landStartTime[i] +landDuration[i];
                int f1=max(lf, waterStartTime[j])+waterDuration[j];
                int wf=waterStartTime[j]+waterDuration[j];
                int f2=max(wf, landStartTime[i])+landDuration[i];
                ans=min(ans, min(f1, f2));
            }
        }
        return ans;
    }
};