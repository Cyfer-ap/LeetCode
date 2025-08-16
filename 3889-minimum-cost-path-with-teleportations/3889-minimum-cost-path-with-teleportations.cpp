
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        const long long INF = (long long)4e18;
        auto id = [&](int i, int j){ return i * n + j; };
        int N = m * n;

        vector<int> val(N);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                val[id(i,j)] = grid[i][j];

        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b){
            if (val[a] != val[b]) return val[a] > val[b]; 
            return a < b;
        });

        vector<vector<int>> groups;
        for (int i = 0; i < N; ) {
            int j = i;
            while (j < N && val[ord[j]] == val[ord[i]]) ++j;
            vector<int> g;
            for (int t = i; t < j; ++t) g.push_back(ord[t]);
            groups.push_back(move(g));
            i = j;
        }

        auto propagate = [&](const vector<long long>& seed) {
            vector<long long> dp(N, INF);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int u = id(i,j);
                    long long best = seed[u];
                    if (i > 0) best = min(best, dp[id(i-1,j)] + grid[i][j]);
                    if (j > 0) best = min(best, dp[id(i,j-1)] + grid[i][j]);
                    dp[u] = best;
                }
            }
            return dp;
        };

        vector<long long> seed(N, INF);
        seed[0] = 0;
        vector<long long> reach = propagate(seed); 

        for (int t = 0; t < k; ++t) {
            vector<long long> seed_next(N, INF);
            long long cur_min = INF;

            for (const auto& g : groups) {
                long long gmin = INF;
                for (int u : g) gmin = min(gmin, reach[u]);
                cur_min = min(cur_min, gmin);
                if (cur_min < INF) {
                    for (int u : g) seed_next[u] = min(seed_next[u], cur_min);
                }
            }

            vector<long long> seed_comb(N);
            for (int u = 0; u < N; ++u) seed_comb[u] = min(reach[u], seed_next[u]);
            reach = propagate(seed_comb);
        }

        long long ans = reach[id(m-1,n-1)];
        return (ans >= INF/2) ? -1 : ans; 
    }
};
