class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1;
        long long e = 100000000000000;
        while(s<=e){
            long long mid = (s+e)/2;

            long long sum = 0;
            for(auto x : time){
                sum+=mid/x;
            }
            if(sum < totalTrips){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return s;
    }
};
