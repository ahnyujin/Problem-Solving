class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret=0;
        while(numBottles >= numExchange) {
            ret += numBottles - numBottles%numExchange;
            numBottles = numBottles%numExchange + numBottles/numExchange;
        }
        ret += numBottles;
        return ret;
    }
};
