class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vt = {0};
        set<char> my_set = {'a','e','i','o','u'};
        int sum=0;
        for(auto x : words){
            if(my_set.contains(x[0]) && my_set.contains(x[x.length()-1])){
                sum++;
            }
            vt.push_back(sum);
        }

        vector<int> ret;
        for(auto q : queries) {
            ret.push_back(vt[q[1]+1]-vt[q[0]]);
        }
        return ret;
    }
};
