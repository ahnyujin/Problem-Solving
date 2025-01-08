class Solution {
public:
    bool isPrefixAndSuffix(string& str1, string& str2) {
        int str1len = str1.size();
        int str2len = str2.size();
        if(str1len==0) return true;
        if(str1len > str2len) return false;

        for(int i=0;i<str1len;i++){
            if(str1[i]!=str2[i]) return false;
            if(str1[i]!=str2[str2len-(str1len-i)]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret=0;
        int size = words.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                ret += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ret;
    }
};
