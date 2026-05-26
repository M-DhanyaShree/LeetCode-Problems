class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int uf[26]={0},lf[26]={0},i,ans=0;
        for(i=0;i<word.length();i++)
        {
            if(word[i]>='A' && word[i]<='Z') uf[word[i]-'A']=1;
            else lf[word[i]-'a']=1;
        }    
        for(i=0;i<26;i++)
        {
            if(uf[i]==1 && lf[i]==1) ans++;
        }
        return ans;
    }
};