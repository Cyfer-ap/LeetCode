class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = letters.size();
        unordered_map<char, int> lc;
        for (char c : letters) {
            lc[c]++;
        }
        return backtrack(words, lc, score, 0);
    }

private:
    int backtrack(vector<string>& words, unordered_map<char, int>& lc, vector<int>& score, int index) {
        if (index == words.size()) return 0;

        int ms = 0;

        ms = max(ms, backtrack(words, lc, score, index + 1));

        string word = words[index];
        unordered_map<char, int> wc;
        int ws = 0;

        for (char c : word) {
            wc[c]++;
            ws += score[c-'a'];
        }
        bool cf = true;
        for (auto& [c, count] : wc) {
            if (lc[c] < count) {
                cf = false;
                break;
            }
        }
        if (cf) {
            for (auto& [c, count] : wc) {
                lc[c] -= count;
            }
            ms = max(ms, ws + backtrack(words, lc, score, index+1));

            for (auto& [c, count] : wc) {
                lc[c] += count;
            }
        }
        return ms;
    }
};
