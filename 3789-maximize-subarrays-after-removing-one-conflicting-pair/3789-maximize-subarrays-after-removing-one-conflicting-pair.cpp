class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        
        for(int i = 0; i < m; ++i) {
            if(conflictingPairs[i][0] > conflictingPairs[i][1]) {
                swap(conflictingPairs[i][0], conflictingPairs[i][1]);
            }
        }
        
        sort(conflictingPairs.begin(), conflictingPairs.end(), 
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        
        long long blocked = 0;
        long long profit = 0;
        long long maxProfit = 0;
        long long max1 = 0;
        long long max2 = 0;
        
        for(int i = 0; i < m; ++i) {
            int start = conflictingPairs[i][0];
            int end = conflictingPairs[i][1];
            int bottom = (i < m - 1) ? conflictingPairs[i + 1][1] : n + 1;
            int gap = bottom - end;
            
            if(start > max1) {
                max2 = max1;
                max1 = start;
                profit = 0;
            } else if(start > max2) {
                max2 = start;
            }
            
            profit += (max1 - max2) * gap;
            if(profit > maxProfit) {
                maxProfit = profit;
            }
            
            blocked += max1 * gap;
        }
        
        long long totalSubarrays = (long long)n * (n + 1) / 2;
        return totalSubarrays - blocked + maxProfit;
    }
};