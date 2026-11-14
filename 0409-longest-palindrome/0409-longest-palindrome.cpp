class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0,flag=0;
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        for(auto& p:mp) {
            if(p.second%2!=0) {
                flag=1;
                ans+=p.second-1;
            }
            else ans+=p.second;
        }
        return (flag==0)?ans:ans+1;
    }
};