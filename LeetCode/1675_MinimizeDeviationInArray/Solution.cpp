class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int size = nums.size();
        int min_val = INT_MAX;
        priority_queue<int> pq;
        for(int i=0;i<size;i++){
            if(nums[i]%2==0){
                pq.push(nums[i]);
                min_val = min(nums[i],min_val);
            }
            else{
                pq.push(nums[i]*2);
                min_val = min(nums[i]*2,min_val);
            }
        }

        int answer=INT_MAX;
        while(!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            
            answer = min(answer, cur-min_val);
            if(cur%2!=0) break;
            pq.push(cur/2);
            min_val = min(min_val, cur/2);
        }
        return answer;
    }
};
