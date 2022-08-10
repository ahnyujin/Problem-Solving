class Solution {
public:
   vector<string> ret;
   void rec(string str, int n, int cur) {
        if(str.size()==n*2){
            ret.push_back(str);
        }
        if(n>cur){
            rec(str+'(', n, cur+1);
        }
        if(cur>str.size()-cur) {
            rec(str+')', n, cur);
        }
    }
    vector<string> generateParenthesis(int n) {
        rec("", n, 0);
        return ret;
    }
};
