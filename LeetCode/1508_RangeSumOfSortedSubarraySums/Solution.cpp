class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int size = n*(n+1)/2;
        int subSum[size];

        int cnt = 0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                subSum[cnt++]=sum;
            }
        }

        sort(subSum, subSum+size);

        int ret = 0;
        int mod = 1e9+7;
        for(int i=left-1;i<right;i++){
            ret = (ret+subSum[i])%mod;
        }
        return ret;
    }
};
