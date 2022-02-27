class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int size=time.size();
        vector<int> table(60, 0);
        int answer=0;
        for(int i=0;i<size;i++){
            int cur=time[i]%60;
            answer+=table[(60-cur)%60];
            table[cur]++;
        }
        return answer;
    }
};