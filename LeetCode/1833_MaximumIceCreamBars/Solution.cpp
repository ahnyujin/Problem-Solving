class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : costs){
            pq.push(it);
        }
        int n = costs.size();
        int ret = 0;
        for(int i=0;i<n;i++){
            int cur = pq.top();
            pq.pop();
            if(coins >= cur){
                ret++;
                coins-= cur;
            }
        }
        return ret;
    }
};
