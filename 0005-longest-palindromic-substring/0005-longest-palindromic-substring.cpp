class Solution {
public:
    string longestPalindrome(string s) {
        int i,len=1,n=s.size(),st=0;
        for(i=0;i<n;i++) {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l+1>len) {
                    len=r-l+1;
                    st=l;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l+1>len) {
                    len=r-l+1;
                    st=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(st,len);
    }
};