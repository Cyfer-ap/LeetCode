class Solution {
public:
    void backtrack(vector<int>& candidates, int target, 
        vector<vector<int>>& result, vector<int>& current, int start, 
        int currentSum){
            if(currentSum == target){
                result.push_back(current);
                return;
            }

            if(currentSum > target) return;

            for(int i = start; i < candidates.size(); ++i){
                if(i  > start && candidates[i] == candidates[i-1]) continue;

                current.push_back(candidates[i]);
                backtrack(candidates, target, result, current, i+1, currentSum + candidates[i]);
                current.pop_back();
            }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, result, current, 0, 0);

        return result;
    }
};