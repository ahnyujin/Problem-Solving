class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int size = s.length();
        vector<int> table(size);
        for(auto shift : shifts) {
            if(shift[2]==1){
                table[shift[0]]++;
                if(shift[1]+1!=size){
                    table[shift[1]+1]--;
                }
            }
            else{
                table[shift[0]]--;
                if(shift[1]+1!=size){
                    table[shift[1]+1]++;
                }
            }
        }

        int shiftCount=0;
        for(int i=0;i<size;i++){
            shiftCount= (shiftCount + table[i])%26;
            if(shiftCount < 0){
                shiftCount+=26;
            }
            s[i]=((s[i]-'a'+shiftCount))%26+'a';
        }
        return s;
    }
};
