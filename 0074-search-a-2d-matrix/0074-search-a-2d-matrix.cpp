class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        int l = 0;
        int r = n - 1;
        int idx = 0;
        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;
        while (l<=r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target) {
                l = mid + 1;
                idx = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if (idx == -1) return false;

        l = 0;
        r = m-1;
        while (l<=r) {
            int mid = l + (r - l) / 2;
            int val = matrix[idx][mid];
            if (val == target) return true;
            if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
