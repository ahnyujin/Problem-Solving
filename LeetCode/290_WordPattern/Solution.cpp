class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> vt;
        string word;
        while(ss >> word) {
            vt.push_back(word);
        }

        map<char, string> patternToWord;
        set<string> words;
        int len = pattern.length();
        if(vt.size()!=len) return false;
        for(int i=0;i<len;i++){
            if(patternToWord.find(pattern[i])!=patternToWord.end()){
                if(patternToWord[pattern[i]]!=vt[i]) return false;
            }
            else{
                if(words.find(vt[i])!=words.end()) return false;
                patternToWord[pattern[i]]=vt[i];
                words.insert(vt[i]);
            }
        }
        return true;
    }
};
