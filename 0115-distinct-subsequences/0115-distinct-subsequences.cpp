class Solution {
public:
    int count(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if (j == t.size()) return 1;  // matched entire t
        if (i == s.size()) return 0;  // s exhausted before t

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            // Use s[i] or skip it
            dp[i][j] = count(s, t, i+1, j+1, dp) + count(s, t, i+1, j, dp);
        } else {
            // Only skip s[i]
            dp[i][j] = count(s, t, i+1, j, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(s, t, 0, 0, dp);
    }
};
