class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        
        int a =0, c = 0, b = -prices[0];
        
        for(int i=1; i<prices.size(); i++){
            int temp = a;
            a = max(a, c);
            int t = b;
            b= max(b, temp - prices[i]);
            c = t + prices[i];
        }
        return max(a, c);
    }
};
