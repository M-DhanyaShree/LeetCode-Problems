class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j;
        string ans="";
        sort(strs.begin(), strs.end());
        string f=strs[0],l=strs[strs.size()-1];
        for(i=0;i<min(f.size(),l.size());i++) {
            if(f[i]!=l[i]) break;
            else ans+=f[i];
        }
        return ans;
    }
};