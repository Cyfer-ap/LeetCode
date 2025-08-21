class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n/3;
        unordered_map<int, int> s;
        for(int i=0; i<n; i++){
            s[nums[i]]++;
        }
        vector<int> res;
        for (auto &p : s){
            if(p.second > m){
                res.emplace_back(p.first);
            }
        }
        return res;
    }
};