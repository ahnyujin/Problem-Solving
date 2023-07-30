class Solution {
public:
    vector<vector<int>> table;
    int getMinCount(int start, int end, string& s){
        if(table[start][end]!=-1){
            return table[start][end];
        }
        if(start==end){
            return table[start][end]=1;
        }
        int ret;
        if(s[start]==s[end]||s[start]==s[start+1]){
            ret = getMinCount(start+1,end,s);
        }
        else if (s[end-1]==s[end]){
            ret = getMinCount(start, end-1, s);
        }
        else{
            ret = getMinCount(start+1,end,s)+1;
            for(int k=end-1;k>start;k--){
                if(s[k]==s[start])
                    ret=min(ret, getMinCount(start,k,s)+getMinCount(k+1,end,s));
            }
        }
        return table[start][end]=ret;
    }
    int strangePrinter(string s) {
        int n = s.size();
        table.assign(n, vector<int>(n,-1));
        int answer=getMinCount(0, n-1, s);
        return answer;
    }
};
