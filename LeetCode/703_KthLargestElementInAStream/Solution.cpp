class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int num;
    KthLargest(int k, vector<int>& nums) {
        num=k;
        for(auto x : nums){
            q.push(x);
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>num){
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
