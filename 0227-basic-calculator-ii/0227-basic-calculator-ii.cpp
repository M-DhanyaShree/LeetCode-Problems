class Solution {
public:
    int calculate(string s) {
        char prev='+';
        long long curr=0;
        int i;
        stack<int> st;
        for(i=0;i<s.size();i++) {
            char c=s[i];
            if(isdigit(c)) curr=curr*10+(c-'0');
            if(!isdigit(c) && !isspace(c) || i==s.length()-1) {
                if(prev=='+') st.push(curr);
                else if(prev=='-') st.push(-curr);
                else if(prev=='*') {
                    int tp=st.top();
                    st.pop();
                    st.push(tp*curr);
                }
                else if(prev=='/') {
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                prev=c;
                curr=0;
            }
        }
        long long res=0;
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};