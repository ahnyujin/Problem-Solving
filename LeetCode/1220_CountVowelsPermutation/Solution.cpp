class Solution {
public:
    int countVowelPermutation(int n) {
        int table[20001][5];
        for(int i=0;i<5;i++){
            table[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            table[i][0]=table[i-1][1]; // a
            table[i][1]=(table[i-1][0]+table[i-1][2])%1000000007; // e
            table[i][2]=(((table[i-1][0]+table[i-1][1])%1000000007+table[i-1][3])%1000000007+table[i-1][4])%1000000007; // i
            table[i][3]=(table[i-1][2]+table[i-1][4])%1000000007; // o
            table[i][4]=table[i-1][0]; // u
        }
        int ret = 0;
        for(int i=0;i<5;i++){
            ret+=table[n][i];
            ret%=1000000007;
        }
        return ret;
    }
};
