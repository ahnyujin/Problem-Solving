class Solution {
public:
    int minimumLength(string s) {
        vector<int> table(26, 0);
        for (auto x : s) {
            table[x - 'a']++;
        }

        int ret = 0;
        for (auto count : table) {
            if (count == 0) continue;
            if (count % 2 == 0) {
                ret +=2;
            } else {
                ret +=1;
            }
        }
        return ret;
    }
};
