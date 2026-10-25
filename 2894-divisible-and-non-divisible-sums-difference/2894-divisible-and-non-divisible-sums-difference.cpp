class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tot,k,num1,num2;
        tot=n*(n+1)/2;
        k=n/m;
        num2=k*(k+1)/2*m;
        num1=tot-num2;
        return num1-num2;
    }
};