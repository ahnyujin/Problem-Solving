class Solution {
public:
    vector<int> ret;
    void orderNumber(int index, int n) {
        for(int i=0;i<=9;i++){
            int cur = index + i;
            if(cur==0) continue;
            if(cur>n) return;
            ret.push_back(cur);
            orderNumber(cur*10, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        orderNumber(0, n);
        return ret;
    }
};
