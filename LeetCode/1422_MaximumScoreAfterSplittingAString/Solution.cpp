class Solution {
public:
    int maxScore(string s) {
        int sum=0;
        int cnt=0;
        int max=-500;
        int size = s.size();
        for(int i=0;i<size;i++){
            int x = s[i];
            if(x=='1'){
                sum++;
                cnt--;
            } else{
                cnt++;
            }
            if(cnt>max&&i!=size-1){
                max=cnt;
            }
        }
        return sum+max;
    }
};
