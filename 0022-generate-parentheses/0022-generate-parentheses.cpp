class Solution {
public:
    void solve(int n, int open, int close, string current, vector<string>& result){
        
        if(current.length() == n * 2){
            result.push_back(current);
            return;
        }

        if (open < n){
            solve(n, open+1, close, current + "(", result);
        }

        if(close < open){
            solve(n, open, close+1, current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, 0, "", result);
        return result;
    }
};