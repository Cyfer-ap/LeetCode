
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or end is blocked, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        // dp[i][j] = number of ways to reach cell (i, j)
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Start cell has exactly 1 way (standing there)
        dp[0][0] = 1;

        // Fill first row: can only come from the left
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];   // carry over if no obstacle
            } // else stays 0 (blocked or unreachable after an obstacle)
        }

        // Fill first column: can only come from above
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];   // carry over if no obstacle
            } // else stays 0
        }

        // Fill the rest: from top + left if current cell isn't blocked
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0; // obstacle => 0 ways
                }
            }
        }

        // Convert to int to match function signature
        return static_cast<int>(dp[m - 1][n - 1]);
    }
};
