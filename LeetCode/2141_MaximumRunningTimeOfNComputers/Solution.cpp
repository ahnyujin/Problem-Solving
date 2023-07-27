class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s=1;

        long long sum = 0;
        for(int battery : batteries) {
            sum+=battery;
        }
        long long e=sum/n;

        while (s < e){
            long long mid = (s+e+1)/2;
            long long time = 0;
            for(int battery : batteries){
                time += min((long long)battery, mid);
            }

            if(mid*n <= time){
                s = mid;
            }
            else {
                e = mid-1;
            }
        }
        return s;
    }
};
