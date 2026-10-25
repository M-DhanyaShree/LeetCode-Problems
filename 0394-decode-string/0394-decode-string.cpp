class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> term;
        string curr="";
        int k=0,i;
        for(char c:s) {
            if(isdigit(c)) k=k*10+(c-'0');
            else if(c=='[') {
                cnt.push(k);
                term.push(curr);
                k=0;
                curr="";
            }
            else if(c==']') {
                int n=cnt.top();
                cnt.pop();
                string temp=term.top();
                term.pop();
                for(i=0;i<n;i++) temp+=curr;
                curr=temp;
            }
            else curr+=c;
        }   
        return curr;
    }
};