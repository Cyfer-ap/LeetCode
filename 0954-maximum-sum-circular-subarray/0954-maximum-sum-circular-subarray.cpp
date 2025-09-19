class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        long long total = nums[0];
        long long max_end = nums[0], max_far = nums[0];
        long long min_end = nums[0], min_far = nums[0];

        for(int i=1; i< n; i++){
            int x = nums[i];
            max_end = max((long long)x, max_end + x); 
            max_far = max(max_far, max_end);

            min_end = min((long long)x, min_end+x);
            min_far = min(min_far, min_end);

            total += x;
        }

        if(max_far < 0) return max_far;

        long long wrap = total - min_far;
        return max(max_far, wrap);
    }
};