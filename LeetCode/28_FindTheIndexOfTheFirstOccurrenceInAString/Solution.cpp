class Solution {
public:
    vector<int> getPi(string& needle){
        int size=needle.size();
        vector<int> pi(size,0);
        int j=0;
        for(int i=1;i<size;i++){
            if(j>0 && needle[i]!=needle[j]){
                j=pi[j-1];
            }
            if(needle[i]==needle[j]){
                pi[i]=++j;
            }
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        auto pi = getPi(needle);
        int size = haystack.size();
        int needle_size = needle.size();
        int j=0;
        for(int i=0;i<size;i++){
            while(j>0 && haystack[i]!=needle[j]){
                j=pi[j-1];
            }
            if(haystack[i]==needle[j]){
                if(j==needle_size-1){
                    return i-needle_size+1;
                }
                else{
                    j++;
                }
            }
        }
        return -1;
    }
};
