class Solution {
public:
    void solve(int n, string current, vector<string>& result, char prev){
        if(n==0){
            result.push_back(current);
            return;
        }

        solve(n-1,current+'1', result, '1');

        if(prev != '0'){
            solve(n-1, current+'0', result, '0');
        }
    }

    vector<string> validStrings(int n) {
        vector<string> result;
        solve(n,"", result, '1');
        return result;
    }
};