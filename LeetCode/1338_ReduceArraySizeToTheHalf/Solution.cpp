class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int table[100001];
        memset(table, 0, sizeof table);
        for(int cur : arr){
            table[cur]++;
        }
        priority_queue<int, vector<int>> pq;
        for(int i=1;i<=100000;i++){
            if (table[i]==0) continue;
            pq.push(table[i]);
        }
        int sum = 0;
        int size = arr.size();
        int ret = 0;
        while(!pq.empty()){
            ret++;
            sum+=pq.top();
            pq.pop();
            if(sum*2>=size){
                return ret;
            }
        }
        return ret;
    }
};
