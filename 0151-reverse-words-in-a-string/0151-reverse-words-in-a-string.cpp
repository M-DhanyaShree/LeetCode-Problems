class Solution {
public:
    string reverseWords(string s) {
        int i,j;
        string ans;
        i=s.size()-1;
        while(i>=0) {
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            j=i;
            while(i>=0 && s[i]!=' ') {
                i--;
            }
            string word=s.substr(i+1,j-i);
            if(!ans.empty()) {
                ans+=" ";
            }
            ans+=word;
        }
        return ans;
    }
};