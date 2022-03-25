class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        
        int a = 0;
        int b = -(prices[0]+fee);
        
        for(int i=1; i<prices.size(); i++){
            int temp = a;
            a = max(a, b+prices[i]);
            b = max(b, temp - (prices[i]+fee));
        }
        return max(a, b);
    }
};
