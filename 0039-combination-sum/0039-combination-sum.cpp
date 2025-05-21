class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result,
     vector<int>& current, int index, int currentsum){
        if(currentsum == target){
            result.push_back(current);
            return;
        }

        if(currentsum > target) return;

        for(int i = index; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            backtrack(candidates, target, result, current, i, currentsum + candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(candidates, target, result, current, 0, 0);

        return result;
    }
};