class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,ob=0;
        for(char c:s) {
            if(c=='(') ob++;
            else {
                if(ob>0) ob--;
                else cnt++;
            }
        }
        return ob+cnt;
    }
};