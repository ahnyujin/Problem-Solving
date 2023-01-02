class Solution {
public:
    bool isUpperCase(char x) {
        return x<='Z';
    }
    bool detectCapitalUse(string word) {
        int len=word.length();
        int upper=0;
        int lower=0;
        for(auto c : word) {
            if(isUpperCase(c)){
                upper++;
            }
            else {
                lower++;
            }
        }
        if(upper==len)return true;
        if(lower==len)return true;
        if(lower==len-1 && isUpperCase(word[0]))return true;
        return false;
    }
};
