class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=(int)s.size()-1;
        while(i<j){
            while(i < j){
                while(i < j && !isalnum(s[i])) ++i;
                while(i < j && !isalnum(s[j])) --j;

                char left = tolower(s[i]);
                char right = tolower(s[j]);
                if(left!=right) return false;
                ++i;
                --j;
            }
        }
        return true;
    }
};