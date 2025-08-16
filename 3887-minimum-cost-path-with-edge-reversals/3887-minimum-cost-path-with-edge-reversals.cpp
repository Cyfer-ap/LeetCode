class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> incoming(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});      
            incoming[v].push_back({u, w});  
        }
    
        for (int u = 0; u < n; ++u) {
            for (auto &inc : incoming[u]) {
                int x = inc.first, w = inc.second;
                adj[u].push_back({x, 2*w});
            }
        }
     
        const long long INF = (1LL<<62);
        vector<long long> dist(n, INF);
        dist[0] = 0;
    
        using State = pair<long long,int>;  
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            if (u == n-1) return d;  
    
            for (auto [v, w] : adj[u]) {
                long long nd = d + (long long)w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return -1; 
    }
};




