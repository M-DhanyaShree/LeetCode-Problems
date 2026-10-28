class Solution {
public:
    int calculate(string s) {
        long long num=0,res=0;
        int sign=1;
        stack<int> st;
        for(char c:s) {
            if(isdigit(c)) num=num*10+(c-'0');
            else if(c=='+') {
                res+=sign*num;
                num=0;sign=1;
            }
            else if(c=='-') {
                res+=sign*num;
                num=0;sign=-1;
            }
            else if(c=='(') {
                st.push(res);
                st.push(sign);
                res=0;sign=1;
            }
            else if(c==')') {
                res+=sign*num;
                num=0;
                int prev=st.top();
                st.pop();
                res*=prev;
                long long pr=st.top();
                st.pop();
                res+=pr;
            }
        }
        res+=sign*num;
        return res;
    }
};