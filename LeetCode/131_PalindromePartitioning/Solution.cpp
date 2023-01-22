class Solution {
public:
    vector<vector<string>> answer;
    bool isPalindrome(int start, int end, string& x){
        int size = (end-start+1)/2;
        for(int i=0;i<size;i++){
            if(x[start+i]!=x[end-i])return false;
        }
        return true;
    }
    void dfs(int start, int end, vector<string>& temp, string& s){
        if(start>end){
            answer.push_back(temp);
        }
        else{
            for(int i=start;i<=end;i++){
                if(isPalindrome(start, i, s)){
                    temp.push_back(s.substr(start, i-start+1));
                    dfs(i+1, end, temp, s);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        dfs(0, s.length()-1, temp, s);
        return answer;
    }
};
