class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k)return false;
        
        vector<int> table(26,0);
        for(auto c : s) {
            table[c-'a']++;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(table[i]%2==1){
                count++;
            }
        }

        return count <= k;
    }
};
