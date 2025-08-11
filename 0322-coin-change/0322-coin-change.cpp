class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int c : coins) {
            for (int s =c; s <= amount; s++) {
                dp[s] = min(dp[s], dp[s-c]+1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
