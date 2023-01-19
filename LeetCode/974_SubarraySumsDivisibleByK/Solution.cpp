class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> table(k,0);
        table[0]=1;
        int answer=0;
        int prefixRemainder = 0;
        for(auto num : nums){
            prefixRemainder=(prefixRemainder+num%k+k)%k;
            answer+=table[prefixRemainder];
            table[prefixRemainder]++;
        }
        return answer;
    }
};
