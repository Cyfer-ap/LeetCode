class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int length = 0;

        for(int i = 1; i<n; i++){
            while(length > 0 && s[i] != s[length]){
                length = lps[length-1];
            }
            if (s[i] == s[length]) {
                ++length;
                lps[i] = length;
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};