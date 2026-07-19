class Solution {
private:
    static bool comparator(pair<int,char> p1,pair<int,char> p2) {
        if(p1.first>p2.first) return true;
        if(p1.first<p2.first) return false;
        return p1.second<p2.second;
    }

public:
    string frequencySort(string s) {
        pair<int,char> freq[128];
        int i;
        for(i=0;i<128;i++) {
            freq[i]={0,(char)i};
        }
        for(i=0;i<s.size();i++) {
            freq[(unsigned char)s[i]].first++;
        }
        sort(freq,freq+128,comparator);
        string ans="";
        for(i=0;i<128;i++) {
            while(freq[i].first--) {
                ans+=freq[i].second;
            }
        }
        return ans;
    }
};