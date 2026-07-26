class Solution {
public:
    string reverseWords(string s) {
        int i,j,n=s.size();
        string ans="";
        i=n-1;
        while(i>=0) {
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            j=i;
            while(i>=0 && s[i]!=' ') i--;
            if(!ans.empty()) ans+=' ';
            ans+=(s.substr(i+1,j-i));
        }
        return ans;
    }
};