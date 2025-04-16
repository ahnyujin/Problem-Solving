class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long total = 0;
        int n = nums.size();
        int left = 0;
        long long pairCount = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++) {
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            while (pairCount >= k) {
                total += n - right;
                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }
        }

        return total;
    }
};
