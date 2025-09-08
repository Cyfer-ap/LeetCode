class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int len = s.length();

        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < len; i++) {
            mp[s[i]].push_back(i);
        }

        int cntOfMatches = 0;
        for(auto word: words) {

            bool isMatch = true;
            int lastPos = -1;
            for(auto ch: word) {

                if(mp.find(ch) == mp.end()) {
                    isMatch = false;
                    break;
                }

                auto itr = upper_bound(mp[ch].begin(), mp[ch].end(), lastPos);

                if(itr == mp[ch].end()) {
                    isMatch = false;
                    break;
                } 

                lastPos = *itr;
            }

            if(isMatch) {
                cntOfMatches++;
            }
        }

        return cntOfMatches;
    }
};