class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) 
    {
        string ans="";
        int i,j,sum,rem;        
        for(i=0;i<words.size();i++)
        {
            sum=0;            
            for(j=0;j<words[i].size();j++)
            {
                sum+=weights[words[i][j]-'a'];
            }            
            rem=sum%26;
            ans+=('z'-rem);
        }        
        return ans;
    }
};