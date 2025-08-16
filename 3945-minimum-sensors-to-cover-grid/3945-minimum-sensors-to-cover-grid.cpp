class Solution {
public:
    int minSensors(int n, int m, int k) {
        long long d = 2LL * k+1;
        long long rows = (n+d-1) / d;
        long long cols = (m+d-1) / d;
        return rows*cols;
    }
};

