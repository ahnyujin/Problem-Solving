class Solution {
public:
    int firstUniqChar(string s) {
        int table[26];
        memset(table, 0, sizeof table);
        int ret = 0;
        for(char cur : s) {
            table[cur-'a']++;
        }
        int len = s.length();
        for(int i=0;i<len;i++) {
            if(table[s[i]-'a']==1) {
                return i;
            }
        }
        return -1;
    }
};
