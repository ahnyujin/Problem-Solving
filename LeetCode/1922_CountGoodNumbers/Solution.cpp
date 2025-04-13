class Solution {
public:
    int mod = 1000000007;
    long long total(long long n, long long m) {
        if(m==0){
            return 1;
        }
        if(m%2==0){
            long long result = total(n,m/2)%mod;
            return (result%mod)*(result%mod)%mod;
        }
        long long result = total(n,m-1)%mod;
        return (result*n)%mod;

    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            long long m = n/2;
            return (total(5,m)%mod)*(total(4,m)%mod)%mod;
        }
        long long m = n/2;
        return (total(5,m+1)%mod)*(total(4,m)%mod)%mod;
    }
};
