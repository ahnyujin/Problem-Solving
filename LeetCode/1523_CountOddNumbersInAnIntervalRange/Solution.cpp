class Solution {
public:
    int countOdds(int x){
        if (x<0) return 0;
        return x/2 + x%2;
    }
    int countOdds(int low, int high) {
        return countOdds(high) - countOdds(low-1);
    }
};
