class Solution {
public:
    int myAtoi(string s) {
        int sign=1,n=s.size(),i=0;
        long long ans=0;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-' || s[i]=='+') {
            sign=(s[i]=='-')?(-1):1;
            i++;
        }  
        while(i<n && s[i]>='0' && s[i]<='9') {
            ans=ans*10+(s[i]-'0');
            if(sign==1 && ans>INT_MAX) return INT_MAX;
            else if(sign==-1 && -ans<INT_MIN) return INT_MIN;
            i++;
        }
        return sign*ans;
    }
};