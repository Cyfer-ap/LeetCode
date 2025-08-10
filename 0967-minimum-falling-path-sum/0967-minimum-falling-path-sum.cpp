class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        const int INF = 0x3f3f3f3f;
        vector<int>dp = matrix.back();

        for (int r = n-2; r >= 0; --r) {
            vector<int> ndp(n, INF);
            for (int c=0; c < n; ++c) {
                int best = dp[c];
                if (c>0) best = min(best, dp[c-1]);
                if (c+1 < n) best = min(best, dp[c+1]);

                ndp[c] = matrix[r][c] + best;
            }
            dp.swap(ndp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
