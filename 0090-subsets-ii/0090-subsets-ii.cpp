class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& current, 
        vector<vector<int>>& result){
            result.push_back(current);

            for(int i = index; i < nums.size(); i++){
                
                if(i > index && nums[i] == nums[i-1]) continue;

                current.push_back(nums[i]);
                solve(nums, i+1, current, result);
                current.pop_back();
            }
        }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        sort(nums.begin(), nums.end());

        solve(nums, 0, current, result);

        return result;
    }
};