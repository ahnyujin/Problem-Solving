class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> my_map;
        int answer=0;
        for(auto x : answers){
            my_map[x]++;
        }

        for(auto& x : my_map){
            answer+=ceil((double)x.second / (x.first + 1)) * (x.first + 1);
        }
        return answer;
    }
};
