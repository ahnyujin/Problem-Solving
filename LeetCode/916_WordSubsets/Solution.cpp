class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> min(26, 0);
        for(auto word : words2){
            int len = word.length();
            vector<int> wordMin(26, 0);
            for(int i=0;i<len;i++){
                wordMin[word[i]-'a']++;
            }

            for(int i=0;i<26;i++){
                if(min[i]<wordMin[i]){
                    min[i]=wordMin[i];
                }
            }
        }

        vector<string> ret;
        for(auto word : words1){
            int len = word.length();
            vector<int> wordTable(26, 0);
            for(int i=0;i<len;i++){
                wordTable[word[i]-'a']++;
            }

            bool flag=true;
            for(int i=0;i<26;i++){
                if(wordTable[i]<min[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ret.push_back(word);
            }
        }
        return ret;
    }
};
