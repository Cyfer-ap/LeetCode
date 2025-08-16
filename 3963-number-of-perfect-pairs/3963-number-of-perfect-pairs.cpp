class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for(auto &x : nums){
            x = llabs(x);
        }
        sort(nums.begin(), nums.end());

        long long n = nums.size();
        long long ans = 0;
        long long j = 0;

        for(long long i=0; i<n; i++){
            if(j<i+1){
                j=i+1;
            }
            while(j < n && nums[j] <= 2LL*nums[i]){
                ++j;
            }
            ans += (j-i-1);
        }
        return ans;
        
    }
};