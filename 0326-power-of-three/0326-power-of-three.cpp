class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double r = log10(n)/log10(3);
        return abs(r - round(r)) < 1e-10;
    }
};
