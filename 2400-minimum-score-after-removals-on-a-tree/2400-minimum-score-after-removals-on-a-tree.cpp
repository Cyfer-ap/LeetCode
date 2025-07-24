
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> in(n), out(n), subtreeXor(n);
        int timer = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            in[u] = timer++;
            subtreeXor[u] = nums[u];
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                subtreeXor[u] ^= subtreeXor[v];
            }
            out[u] = timer++;
        };
        dfs(0, -1);

        auto isAncestor = [&](int u, int v) {
            return in[u] <= in[v] && out[v] <= out[u];
        };

        int totalXor = subtreeXor[0];
        int res = INT_MAX;
        // Try all pairs of edges (i, j) where i != j
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;
                if (isAncestor(a, b)) swap(a, b);
                if (isAncestor(b, a)) {
                    // b is ancestor of a
                    int x = subtreeXor[a];
                    int y = subtreeXor[b] ^ subtreeXor[a];
                    int z = totalXor ^ subtreeXor[b];
                    res = min(res, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = subtreeXor[a];
                    int y = subtreeXor[b];
                    int z = totalXor ^ x ^ y;
                    res = min(res, max({x, y, z}) - min({x, y, z}));
                }
            }
        }
        return res;
    }
};