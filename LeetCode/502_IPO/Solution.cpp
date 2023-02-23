class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> vt;
        int ret = w;
        int size = capital.size();
        for(int i=0;i<size;i++){
            vt.push_back({capital[i], profits[i]});
        }
        sort(vt.begin(), vt.end());

        priority_queue<int> pq;
        pq.push(0);
        int ptr = 0;

        while(!pq.empty() && k>=0){
            k--;
            ret+=pq.top();
            pq.pop();
            while(ptr < size && vt[ptr].first <= ret){
                pq.push(vt[ptr].second);
                ptr++;
            }
        }
        return ret;
    }
};
