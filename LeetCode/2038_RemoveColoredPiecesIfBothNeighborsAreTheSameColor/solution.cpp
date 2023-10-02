class Solution {
public:
    bool winnerOfGame(string colors) {
        int scoreA=0;
        int scoreB=0;

        int size = colors.length();
        for(int i=1;i<size-1;i++){
            int prev = colors[i-1];
            int curr = colors[i];
            int next = colors[i+1];

            if(prev=='A' && curr=='A' && next =='A') {
                scoreA++;
            }
            else if(prev=='B' && curr=='B' && next =='B') {
                scoreB++;
            }
        }

        return scoreA>scoreB;
    }
};
