class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int num : nums) total+=num;

        if(abs(target) > total || (target + total) %2 != 0) return 0;

        int ss = (target+total) / 2;

        vector<int> dp(ss+1, 0);
        dp[0] = 1;

        for(int num : nums){
            for(int j = ss; j >= num; j--){
                dp[j] += dp[j-num];
            }
        }
        return dp[ss];
    }
};