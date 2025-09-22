class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;
        int cnt = 0;
        unordered_map<int, int> fr(n);

        for (int i = 0; i < n; i++) {
            fr[nums[i]]++;
        }

        for(auto& c : fr){
            if(c.second > mx){
                mx = c.second;
            }
        }

        for(auto& c : fr){
            if(c.second == mx){
                cnt++;
            }
        }
        return cnt*mx;
    }
};