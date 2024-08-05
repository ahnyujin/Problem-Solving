class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<string, int> my_map;
        std::vector<string> ret;

        for(const auto it : arr){
            my_map[it]++;
        }

        for(const auto it : arr){
            if(my_map[it] == 1){
                k--;
                if(k==0){
                    return it;
                }
            }
        }
        return "";
    }
};
