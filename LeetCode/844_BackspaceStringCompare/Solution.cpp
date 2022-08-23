class Solution {
public:
    string backspaceGenerator(string s) {
        string ret;
        for(char cur : s) {
            if(cur == '#'){
                if(ret.empty()) continue;
                ret.pop_back();
            }
            else{
                ret.push_back(cur);
            }
        }
        return ret;
    }
    bool backspaceCompare(string s, string t) {
        return backspaceGenerator(s) == backspaceGenerator(t);
    }
};
