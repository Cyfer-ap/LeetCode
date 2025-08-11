class Solution {

static vector<vector<long long>> gs(const vector<int>& a, int start, int len) {
    vector<vector<long long>> g(len+1);
    int m=1<<len;
    for (int mask = 0; mask < m; mask++) {
        int cnt = __builtin_popcount((unsigned)mask);
        long long s = 0;
        for (int i = 0; i < len; i++) {
            if (mask & (1 << i)) {
                s += a[start + i];
            }
        }
        g[cnt].push_back(s);
    }
    return g;
}


public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long half = total / 2;

        vector<vector<long long>> L = gs(nums, 0, n);
        vector<vector<long long>> R = gs(nums, n, n);

        for (int k=0; k <= n; ++k) {
            sort(R[k].begin(), R[k].end());
        }

        long long best = LLONG_MAX;
        for (int k = 0; k < n; ++k) {
            const auto& left = L[k];
            const auto& right = R[n-k];
            for (long long sL : left) {
                long long target = half-sL;
                auto it = lower_bound(right.begin(), right.end(), target);
                if (it != right.end()) {
                    long long picked = sL + *it;
                    best = min(best, llabs(total - 2 * picked));
                }
                if (it != right.begin()) {
                    --it;
                    long long picked = sL + *it;
                    best = min(best, llabs(total -2*picked));
                }
            }
        }
        return (int)best;
    }
};
