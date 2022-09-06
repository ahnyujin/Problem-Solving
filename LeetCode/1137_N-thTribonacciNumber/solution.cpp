class Solution {
public:
    int tribonacci(int n) {
         int a = 1;
        int b = 1;
        int c = 0;
        if(n==0) return c;
        if(n==1) return b;
         for(int i=2;i<n;i++){
             int temp = a;
             a = a+b+c;
             c = b;
             b = temp;
         }
        return a;
    }
};
