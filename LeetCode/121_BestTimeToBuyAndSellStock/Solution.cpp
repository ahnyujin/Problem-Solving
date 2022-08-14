class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        int min=prices[0];
        int ret=0;
        for(int i=0;i<l;i++){
            if(ret<prices[i]-min)ret=prices[i]-min;
            if(min>prices[i]) min=prices[i];
        }
        return ret;
    }
};
