class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> freq;
        int l=0,r=0,big=0;
        while(r<s.length())
        {
            if(freq.find(s[r]) == freq.end())
            {
                freq.insert(s[r]);
                big = max(big,r-l+1);
                r++;
            }
            else
            {
                freq.erase(s[l]);
                l++;
            }
        }
        return big;
    }
};