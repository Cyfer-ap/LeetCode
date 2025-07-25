class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') left++;
            else if(s[i] == ')' && left != 0) left--;
            else if(s[i] == ')' && left == 0) right++;
        }
        return left + right;
    }
};