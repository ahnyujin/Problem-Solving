class Solution {
public:
    double pow(double x, int n) {
        if(n==0) return 1;
        int share = n/2;
        int remainer = n%2;
        double ret = pow(x, share);
        ret*=ret;
        if(remainer){
            ret*=x;
        }
        return ret;
    }
    double myPow(double x, int n) {
        if(n<0){
            return 1/pow(x,n);
        }
        return pow(x,n);
    }
};
