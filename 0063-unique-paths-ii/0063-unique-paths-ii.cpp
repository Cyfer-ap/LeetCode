#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        // If start or end is blocked, 0 paths
        if (g[0][0] == 1 || g[m-1][n-1] == 1) return 0;

        // dp[j] = number of ways to reach current row's cell (i, j)
        // We reuse the same row vector; dp[j] already holds ways from "top".
        vector<long long> dp(n, 0);
        dp[0] = 1; // start cell

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1) {
                    // Obstacle: zero out ways for this cell
                    dp[j] = 0;
                } else if (j > 0) {
                    // dp[j] (top) + dp[j-1] (left)
                    dp[j] += dp[j - 1];
                }
                // For j == 0 and cell not obstacle, dp[0] stays as it is (either 0 or inherited)
            }
        }
        return static_cast<int>(dp[n - 1]);
    }
};
