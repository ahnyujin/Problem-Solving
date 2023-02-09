class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int start=0;
        int ret = 0;
        int size = fruits.size();
        for(int i=0;i<size;i++) {
            int fruit = fruits[i];
            if(map.find(fruit)==map.end()){
                map.insert({fruit,1});
            }
            else{
                map[fruit]++;
            }
            while(map.size()>2){
                map[fruits[start]]--;
                if(map[fruits[start]]==0) map.erase(fruits[start]);
                start++;
            }
            if(ret<i-start+1){
                ret = i-start+1;
            }
        }
        return ret;
    }
};
