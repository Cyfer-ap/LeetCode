using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        auto solve = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = max(
                        dp[i-1][j],
                        dp[i-2 >= 0 ? i-2 : 0][j-1] + arr[i-1]
                    );
                }
            }
            return dp[m][n];
        };
        vector<int> case1(slices.begin(), slices.end() - 1);
        vector<int> case2(slices.begin() + 1, slices.end());
        return max(solve(case1), solve(case2));
    }
};

