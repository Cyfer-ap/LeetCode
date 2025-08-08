#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0;          // early cutoff

        int k = (n + 24) / 25;               // scale by 25 (ceil)
        vector<vector<double>> dp(k + 1, vector<double>(k + 1, -1.0));

        function<double(int,int)> F = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;  // both empty
            if (a <= 0)            return 1.0; // A first
            if (b <= 0)            return 0.0; // B first
            double &res = dp[a][b];
            if (res >= 0.0) return res;

            res = 0.25 * (
                  F(a - 4, b)     // 100,0
                + F(a - 3, b - 1) // 75,25
                + F(a - 2, b - 2) // 50,50
                + F(a - 1, b - 3) // 25,75
            );
            return res;
        }; // <- don't forget this semicolon

        return F(k, k);
    }
};
