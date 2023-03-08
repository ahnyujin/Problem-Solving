class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(auto pile : piles){
            if(pile > max) max = pile;
        }
        int s = 1;
        int e = max;
        while(s<e){
            int mid = (s+e) / 2;
            if(canEatAll(piles, h, mid)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return e;
    }
    bool canEatAll(vector<int>& piles, int h, int k) {
        int sum = 0;
        for(auto pile : piles){
            sum+=(pile/k);
            if(pile%k!=0) sum++;
        }

        return h >= sum;
    }
};
