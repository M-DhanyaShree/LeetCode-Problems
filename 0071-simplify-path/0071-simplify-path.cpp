class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        vector<string> dirs;
        stringstream ss(path);
        string temp;
        while(getline(ss,temp,'/')) {
            if(temp=="" || temp==".") continue;
            else if(temp=="..") {
                if(!dirs.empty()) dirs.pop_back();
            }
            else dirs.push_back(temp);
        }
        for(string s:dirs) {
            ans+= "/"+s;
        }
        return ans.empty()?"/":ans;
    }
};