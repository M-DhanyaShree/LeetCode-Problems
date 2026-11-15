class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n=words.size(),i=0;
        while(i<n) {
            int j=i+1,len=words[i].size();
            while(j<n && len+1+words[j].size()<=maxWidth) {
                len+=1+words[j].size();
                j++;
            }
            int gaps=j-i-1,sp=maxWidth-(len-gaps);
            string line="";
            if(j==n || gaps==0) {
                for(int k=i;k<j;k++) {
                    line+=words[k];
                    if(k<j-1) line+=' ';
                }
                line+=string(maxWidth-line.size(),' ');
            }
            else {
                int base=sp/gaps,rem=sp%gaps;
                for(int k=i;k<j;k++) {
                    line+=words[k];
                    if(k<j-1) {
                        line+=string(base+(rem>0?1:0),' ');
                        if(rem>0) rem--;
                    }
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};