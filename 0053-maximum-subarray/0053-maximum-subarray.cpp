class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> res(n);
        res[0] = nums[0];
        for(int i=1; i<n; i++){
            if(res[i-1] < 0) res[i] = nums[i];
            else{
                res[i] = res[i-1] + nums[i];
            }
        }
        int mx = res[0];
        for(int i=1; i<n; i++){
            if(res[i] > mx){
                mx = res[i];
            }
        }
        return mx;
    }
};