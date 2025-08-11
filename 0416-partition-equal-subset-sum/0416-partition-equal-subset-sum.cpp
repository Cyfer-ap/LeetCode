class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total & 1) return false;      // must be even
        int target = total / 2;

        // If any element is greater than target, impossible
        for (int x : nums) if (x > target) return false;

        vector<char> dp(target + 1, 0);   // dp[s] = can we make sum s?
        dp[0] = 1;

        for (int x : nums) {
            for (int s = target; s >= x; --s) {
                if (!dp[s] && dp[s - x]) dp[s] = 1;
            }
            if (dp[target]) return true;  // early exit
        }
        return dp[target];
    }
};

