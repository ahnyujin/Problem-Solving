class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ret(n,0);
        int size = boxes.size();
        int leftSum = 0;
        int rightSum = 0;
        int leftCulSum = 0;
        int rightCulSum = 0;
        for(int i=0;i<size;i++){
            ret[i] += leftCulSum;
            leftSum+=(boxes[i]-'0');
            leftCulSum+=leftSum;

            int rev = n-1-i;
            ret[rev] += rightCulSum;
            rightSum+=(boxes[rev]-'0');
            rightCulSum+=rightSum;
        }
        return ret;
    }
};
