class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        int result = 1;

        for (int i = 0; i < n; ++i) {
            dp[i][-1] = 1;
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                int len = dp[j].count(mod) ? dp[j][mod] + 1 : 2;
                dp[i][mod] = max(dp[i][mod], len);
                result = max(result, dp[i][mod]);
            }
        }
        return result;
    }
};
