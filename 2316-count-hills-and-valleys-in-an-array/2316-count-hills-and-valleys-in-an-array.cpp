class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> fil;
        fil.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                fil.push_back(nums[i]);
            }
        }

        int count = 0;
        for (int i = 1; i < fil.size() - 1; ++i) {
            if ((fil[i] > fil[i - 1] && fil[i] > fil[i + 1]) || 
                (fil[i] < fil[i - 1] && fil[i] < fil[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
