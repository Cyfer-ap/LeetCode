class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size();
        for (int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> visited(n, false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && bfs(u,v,adj,visited)) {
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
    bool bfs(int u, int v, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        visited[u] = true;
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int &b : adj[a]) {
                if (b == v) return true;
                if (!visited[b]) {
                    q.push(b);
                    visited[b] = true;
                }
            }
        }
        return false;
    }
};