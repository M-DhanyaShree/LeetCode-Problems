class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int i,li[26],ui[26],ans=0;
        fill(li, li+26, -1);
        fill(ui, ui+26, -1);
        for(i=0;i<word.length();i++)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                if(ui[word[i]-'A']==-1)
                    ui[word[i]-'A']=i;
            }
            else
            {
                li[word[i]-'a']=i;
            }
        }
        for(i=0;i<26;i++)
        {
            if(li[i]!=-1 && ui[i]!=-1 && li[i]<ui[i]) ans++;
        }
        return ans;
    }
};