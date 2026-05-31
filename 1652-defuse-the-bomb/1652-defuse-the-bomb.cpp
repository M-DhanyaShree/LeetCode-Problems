class Solution {
public:
    vector<int> calc(vector<int>& code,int l,int r)
    {
        int n=code.size(),i,sum=0;
        vector<int> ans(n,0);
        for(i=l;i<=r;i++) sum+=code[i%n];
        for(i=0;i<n;i++)
        {
            ans[i]=sum;
            sum-=code[l%n];
            l++;r++;
            sum+=code[r%n];
        }
        return ans;
    }
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n=code.size(),l,r;
        if(k==0) return vector<int>(n,0);
        if(k>0)
        {
            l=1;r=k;
            return calc(code,l,r);
        }
        else 
        {
            k=-k;
            l=n-k;
            r=n-1;
            return calc(code,l,r);
        }
    }
};