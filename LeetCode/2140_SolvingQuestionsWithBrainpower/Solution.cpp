class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        vector<long long> table(len);

        table[len-1]=questions[len-1][0];
        for(int i=len-2;i>=0;i--){
            int points = questions[i][0];
            int brainpower = questions[i][1];

            table[i]=points;
            if(i+brainpower+1<len){
                table[i]+=table[i+brainpower+1];
            }
            
            if(table[i]<table[i+1]){
                table[i]=table[i+1];
            }
        }
        return table[0];
    }
};
