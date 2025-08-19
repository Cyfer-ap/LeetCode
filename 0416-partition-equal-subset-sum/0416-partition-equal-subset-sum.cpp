class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int T = sum / 2;
        vector<char> dp(T+1, 0);
        dp[0] = 1;
        for(int x : nums){
            for(int s = T; s >= x; --s){
                dp[s] = dp[s] || dp[s-x];
            }
            if(dp[T]) return true;
        }
        return dp[T];
    }
};