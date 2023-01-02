class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto pile : piles) {
            pq.push(pile);
        }
        int ret=0;
        while(!pq.empty()){
            int top = pq.top();
            if(k!=0){
                top=top/2+top%2;
                pq.push(top);
                k--;
            }
            else{
                ret+=top;
            }
            pq.pop();
        }
        return ret;
    }
};
