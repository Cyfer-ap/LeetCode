class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits.empty()) return {};

        vector<string> result;
        string current;

        vector<string> mapping = {
            "",     "",     "abc",  "def", "ghi", 
            "jkl",  "mno",  "pqrs", "tuv", "wxyz"
        };

        function<void(int)> backtrack = [&](int index){
            if (index == digits.size()){
                result.push_back(current);
                return;
            }

            string letters = mapping[digits[index] - '0'];

            for(char ch : letters){
                current.push_back(ch);
                backtrack(index + 1);
                current.pop_back();
            }
        };
        backtrack(0);
        return result;
    }
};