class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> myMap;
        for(auto x : tasks){
            myMap[x]++;
        }
        int ret=0;
        for(auto [key,value] : myMap){
            cout<<key<<" "<<value;
            if(value==1){
                return -1;
            }
            if(value%3==0){
                ret+=value/3;
            }
            else{
                ret+=value/3+1;
            }
        }
        return ret;
    }
};
