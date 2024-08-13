class Solution {
public:
    int size;
    int tar;
    vector<vector<int>> ret;
    void rec(vector<int>& candidates, int index, vector<int> vt, int sum) {
        if(sum>=tar || index == size) {
            if(sum==tar){
                ret.push_back(vt);
            }
            return;
        }

        for(int i=index;i<size;i++){
            if (i > index && candidates[i]==candidates[i-1])continue;
            if(sum+candidates[i] > tar) break;
            vt.push_back(candidates[i]);
            rec(candidates, i+1, vt, sum+candidates[i]);
            vt.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        size = candidates.size();
        tar = target;
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        rec(candidates, 0, v, 0);
        return ret;
    }
};
