class Solution {
public:
    int maximum69Number (int num) {
        int count = 3;
        int ret_num = num;
        int ret_count = 0;
        while(num!=0){
            if(num%10==6){
                ret_count = count;
            }
            num/=10;
            count*=10;
        }
        return ret_num + ret_count;
    }
};
