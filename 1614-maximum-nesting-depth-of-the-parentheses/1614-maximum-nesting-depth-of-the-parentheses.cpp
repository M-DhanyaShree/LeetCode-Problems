class Solution {
public:
    int maxDepth(string s) {
        int i,curr=0,ans=0;
        for(i=0;i<s.size();i++) {
            if(s[i]=='(') {
                curr++;
                if(curr>ans) ans=curr;
            }
            else if(s[i]==')') {
                curr--;
            }
        }
        return ans;
    }
};