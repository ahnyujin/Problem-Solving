class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.length(); i++) {
            map[order[i]] = i;
        }
        int size = words.size();
        for (int i = 1; i < size; i++) {
            string past = words[i - 1];
            string cur = words[i];

            int n = min(past.length(), cur.length());
            bool flag = false;
            for(int j = 0; j<n; j++) {
                if (map[past[j]] < map[cur[j]]) {
                    flag = true;
                    break;
                }
                else if (map[past[j]] > map[cur[j]]) {
                    return false;
                }
            }

            if(past.length() > cur.length() && !flag) {
                return false;
            }
        }
        return true;
    }
};
