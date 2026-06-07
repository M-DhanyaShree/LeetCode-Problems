class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i,b=prices[0],p=0;
        for(i=0;i<prices.size();i++)
        {
            if(b>prices[i]) b=prices[i];
            else if(prices[i]-b>p) p=prices[i]-b;
        }    
        return p;
    }
};