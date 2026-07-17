class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int i,n;
        for(i=0;i<goal.size();i++) {
            if(goal[i]==s[0]) {
                n=goal.size()-i;
                string f=goal.substr(i,n);
                string l=goal.substr(0,i);
                if(f==s.substr(0,n) && l==s.substr(n)) return true;
            }
        }
        return false;
    }
};