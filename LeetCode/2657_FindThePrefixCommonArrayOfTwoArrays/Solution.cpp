class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int count = 0;

        vector<bool> table(51, false);
        vector<int> ret;
        for(int i = 0; i < n; i++){
            if(table[A[i]]){
                count++;
            } else {
                table[A[i]] = true;
            }

            if(table[B[i]]){
                count++;
            } else {
                table[B[i]] = true;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
