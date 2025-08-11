class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long total = 0;
        for (int x : nums) total += x;

        if (llabs((long long)target) >total) return 0;
        long long tmp = target + total;
        if (tmp & 1LL) return 0;

        int want = (int)(tmp/2);
        vector<long long> dp(want + 1, 0);
        dp[0] = 1;

        int zeros = 0;
        for (int x : nums) {
            if (x==0) {
                ++zeros;
                continue;
            }
            for (int s=want; s >= x; --s) {
                dp[s] += dp[s - x];
            }
        }
        long long ways = dp[want];
        while (zeros--) {
            ways <<= 1;
        }
        return ways;
    }
};
