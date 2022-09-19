class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int cur=1;
        for(int i=1;i<n;i++){
            cur = cur+prev;
            prev = cur-prev;
        }
        return cur;
    }
};
