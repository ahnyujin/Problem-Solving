class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        map<char, char> char_map;
        map<char, char> char_map_reverse;
        for(int i=0;i<len_s;i++){
            if(char_map.find(s[i])==char_map.end()){
                if(char_map_reverse.find(t[i])!=char_map_reverse.end()) {
                    return false;
                }
                char_map[s[i]]=t[i];
                char_map_reverse[t[i]] = s[i];
            }
            else {
                if(char_map[s[i]]!=t[i] || char_map_reverse[t[i]]!=s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
