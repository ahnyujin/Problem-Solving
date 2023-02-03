class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> table(numRows, vector<char> (1000,0));
        int x = 0;
        int y = 0;
        for(char c : s){
            table[x][y]=c;
            if(x==numRows-1){
                x--;
                y++;
            }
            else if(y%(numRows-1)==0){
                x++;
            }
            else{
                x--; 
                y++;
            }
        }
        string ret;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=y;j++){
                if(table[i][j]!=0){
                    ret.push_back(table[i][j]);
                }
            }
        }
        return ret;
    }
};
