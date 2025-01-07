class Solution {
public:
    vector<int> getPi(const string& p) {
        int size = p.size();
        vector<int> pi(size, 0);
        int j = 0;

        for(int i=1;i<size;i++){
            while(j > 0 && p[i]!=p[j]){
                j = pi[j -1];
            }
            if(p[i] == p[j]){
                pi[i] = ++j;
            }
        }
        return pi;
    }

    bool kmp(const string& str, const string& substr) {
        if(substr.empty()) return true;
        if(str.length() < substr.length()) return false;

        vector<int> pi = getPi(substr);
        int j = 0;

        int size= str.length();
        for(int i=0;i<size;i++){
            while(j>0 && str[i] != substr[j]){
                j = pi[j-1];
            }
            if(str[i]==substr[j]){
                if(j==substr.length()-1){
                    return true;
                } else{
                    j++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& x, const string &y) -> bool{
            return x.length() < y.length();
        });

        vector<string> res;
        int size=words.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(kmp(words[j], words[i])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
