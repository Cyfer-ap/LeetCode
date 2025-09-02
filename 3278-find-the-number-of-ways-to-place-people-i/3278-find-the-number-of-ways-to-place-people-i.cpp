class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        long long ans = 0; // count may fit in int for n<=50, but use long long safely

        for (int i = 0; i < n; ++i) {
            int xi = points[i][0], yi = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int xj = points[j][0], yj = points[j][1];

                // Check "upper-left": A=points[i], B=points[j]
                if (xi <= xj && yi >= yj) {
                    bool empty = true;
                    int minx = min(xi, xj), maxx = max(xi, xj);
                    int miny = min(yi, yj), maxy = max(yi, yj);

                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int xk = points[k][0], yk = points[k][1];
                        if (minx <= xk && xk <= maxx && miny <= yk && yk <= maxy) {
                            empty = false; // a third point lies inside/on the border
                            break;
                        }
                    }
                    if (empty) ++ans;
                }
            }
        }
        return (int)ans;
    }
};