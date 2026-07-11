class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0,i;
        for(i=0;i<s.size();i++) {
            if(cnt==0) {cnt++;continue;}
            if(s[i]=='(') {
                if(cnt>0) ans+=s[i]; 
                cnt++;
            } 
            else if(s[i]==')') {
                cnt--;
                if(cnt>0) ans+=s[i];
            }
        }
        return ans;
    }
};