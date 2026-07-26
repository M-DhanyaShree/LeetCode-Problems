class Solution {
    int beauty(vector<int> freq) {
        int min=INT_MAX,max=INT_MIN;
        for(int i=0;i<26;i++) {
            min=(freq[i]<min && freq[i]!=0)?freq[i]:min;
            max=(freq[i]>max && freq[i]!=0)?freq[i]:max;
        }
        return max-min;
    }
public:
    int beautySum(string s) {
        int i,j,n=s.size(),ans=0;
        for(i=0;i<n;i++) {
            vector<int> freq(26,0);
            for(j=i;j<n;j++) {
                freq[s[j]-'a']++;
                ans+=beauty(freq);
            }
        }
        return ans;
    }
};