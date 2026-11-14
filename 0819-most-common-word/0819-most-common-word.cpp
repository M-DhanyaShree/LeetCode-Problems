class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph=regex_replace(paragraph,regex("[[:punct:]]+")," ");
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        unordered_set<string> ban(banned.begin(),banned.end());
        stringstream ss(paragraph);
        string w;
        unordered_map<string,int> mp;
        while(ss>>w) {
            if(ban.find(w)==ban.end()) mp[w]++;
        }
        string ans; int cnt=0;
        for(auto& p: mp) {
            if(p.second>cnt) {
                cnt=p.second;
                ans=p.first;
            }
        }
        return ans;
    }
};