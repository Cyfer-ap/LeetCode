class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) return false;
        int T = total / 2;
        int n = (int)nums.size();

        vector<vector<int8_t>> dp(n, vector<int8_t>(T + 1, -1));

        function<int8_t(int,int)> dfs = [&](int i, int need) -> int8_t {
            if (need == 0) return 1;
            if (i < 0)     return 0;
            int8_t &res = dp[i][need];
            if (res != -1) return res;

            if (dfs(i - 1, need)) return res = 1;
            if (nums[i] <= need && dfs(i - 1, need - nums[i])) return res = 1;

            return res = 0;
        };

        return dfs(n - 1, T);
    }
};
