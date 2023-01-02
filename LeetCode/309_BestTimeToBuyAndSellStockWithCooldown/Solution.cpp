class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=-0x7fffffff;
        int sell=-0x7fffffff;
        int cooldown=0;
        int preSell;
        for(auto price : prices){
            preSell = sell;
            sell = buy + price;
            buy = max(buy, cooldown - price);
            cooldown = max(cooldown, preSell);
        }
        return max(sell, cooldown);
    }
};
