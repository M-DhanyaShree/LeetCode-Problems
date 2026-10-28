class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length()) return s;
        string ans="";
        int i,j,len=2*numRows-2;
        for(i=0;i<numRows;i++) {
            for(j=0;i+j<s.size();j+=len) {
                ans+=s[j+i];
                if(i>0 && i<numRows-1 && j+len-i<s.size()) ans+=s[j+len-i];
            }
        }
        return ans;
    }
};