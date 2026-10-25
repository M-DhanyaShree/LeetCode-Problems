class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,temp=n,rm;
        while(temp>0) {
            rm=temp%10;
            rev=(rev*10)+rm;
            temp/=10;
        }
        return abs(n-rev);
    }
};