class Solution {
public:
    bool available(int limit, vector<int>& weights, int days){
        int bucket = 0;
        int cnt = 1;
        for(auto weight : weights) {
            if(bucket + weight <= limit){
                bucket += weight;
            }
            else{
                cnt++;
                bucket = weight;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max = 0;
        for(auto weight : weights){
            sum+=weight;
            if(max<weight) max=weight;
        }
        int start = max;
        int end = sum;
        int mid = (start+end)/2;
        while(start<end){
            if(!available(mid, weights, days)){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = (start+end)/2;
        }
        return mid;
    }
};
