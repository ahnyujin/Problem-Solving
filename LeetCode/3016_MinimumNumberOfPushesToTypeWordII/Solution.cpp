class Solution {
public:
    int table[26];
    int minimumPushes(string word) {
        for(auto x : word){
            table[x-'a']++;
        }
        sort(table, table+26, greater<int>());
        int ret=0;
        for(int i=0;i<26;i++){
            ret+=table[i]*(i/8+1);
        }
        return ret;
    }
};
