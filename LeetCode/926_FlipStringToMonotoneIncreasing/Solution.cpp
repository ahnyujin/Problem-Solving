class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ret=0;
        int one=0;
        for(char x : s){
            if(x=='1'){
                one++;
            }
            else {
                ret++;
                ret = min(ret, one);
            }
        }
        return ret;
    }
};
