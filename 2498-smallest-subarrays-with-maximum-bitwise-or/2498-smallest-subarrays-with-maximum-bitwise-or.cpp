class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        vector<int> ls(32,-1);

        for(int i = n-1; i>=0;--i){
            for(int b=0; b<32; b++){
                if(nums[i] & (1 << b)){
                    ls[b] = i;
                }
            }

            int far = i;
            for(int b = 0; b<32; ++b){
                if(ls[b] != -1){
                    far = max(far, ls[b]);
                }
            }
            ans[i] = far - i + 1;
        }
        return ans;
    }
};
