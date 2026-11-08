class Solution {
    bool valid(string no) {
        if(no.size()>3 || no.size()==0) return false;
        if(no.size()>1 && no[0]=='0') return false;
        if(no.size() && stoi(no)>255) return false;
        return true;
    }
    void backtrack(vector<string>& ans,string temp,int idx,int dot,string s) {
        if(dot==3) {
            if(valid(s.substr(idx))) ans.push_back(temp+s.substr(idx));
            return;
        }
        int n=s.size();
        for(int i=idx;i<min(n,idx+3);i++) {
            if(valid(s.substr(idx,i-idx+1))) {
                temp.push_back(s[i]);
                temp.push_back('.');
                backtrack(ans,temp,i+1,dot+1,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        backtrack(ans,temp,0,0,s);
        return ans;
    }
};