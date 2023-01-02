class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
          priority_queue<int, vector<int>, greater<int>> pq;
          int n = capacity.size();
          for(int i=0;i<n;i++){
              pq.push(capacity[i]-rocks[i]);
          }
          int ret = 0;
          while(!pq.empty()){
              int top = pq.top();
              additionalRocks-=top;
              if(additionalRocks>=0){
                  ret++;
              }
              else{
                  break;
              }
              pq.pop();
          }
          return ret;
    }
};
