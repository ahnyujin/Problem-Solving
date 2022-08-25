class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26];
        memset(table, 0, sizeof table);
        for(char cur:magazine){
            table[cur-'a']++;
        }
        for(char cur:ransomNote){
            if(table[cur-'a']==0){
                return false;
            }
            table[cur-'a']--;
        }
        return true;
    }
};
