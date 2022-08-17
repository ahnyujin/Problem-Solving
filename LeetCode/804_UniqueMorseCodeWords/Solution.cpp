class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code_table={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> set;
        for(string word : words) {
            string temp;
            for(char it : word) {
                temp += code_table[it-'a'];
            }
            set.insert(temp);
        }
        return set.size();
    }
};
