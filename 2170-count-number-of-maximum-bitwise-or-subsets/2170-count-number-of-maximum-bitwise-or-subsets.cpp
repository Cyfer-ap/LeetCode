class Solution {
public:
    int count = 0;
    int maxOr = 0;
    void dfs(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        dfs(nums, index+1, currentOr);

        dfs(nums, index+1, currentOr | nums[index]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOr |= num;
        }
        dfs(nums, 0, 0);
        return count;
    }
};
