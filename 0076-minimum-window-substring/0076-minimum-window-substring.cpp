class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int l=0,r=0,cnt=0,n=t.size(),ml=INT_MAX,start=0;
        for(char c:t) mp[c]++;
        while(r<s.size()) {
            if(mp.find(s[r])!=mp.end()) {
                if(mp[s[r]]>0) cnt++;
                mp[s[r]]--;
            }
            while(cnt==n) {
                if(r-l+1<ml) {
                    ml=r-l+1;
                    start=l;
                }
                if(mp.find(s[l])!=mp.end()) {
                    mp[s[l]]++;
                    if(mp[s[l]]>0) cnt--;
                }
                l++;
            }
            r++;
        }
        return ml==INT_MAX?"":s.substr(start,ml);
    }
};