class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            int n = s.size();
            if (n%2!=0) continue;

            int half = n/2;
            int sum = 0;

            for (int j = 0; j < half; ++j) {
                sum+=s[j]-'0';
                sum-=s[j+half]-'0';
            }

            if (sum==0) ret++;
        }
        return ret;
    }
};
