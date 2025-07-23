class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        stack<char> st;
        string temp;
        
        if (x > y) {
            res += removePair(s, 'a', 'b', x);
            res += removePair(s, 'b', 'a', y);
        } else {
            res += removePair(s, 'b', 'a', y);
            res += removePair(s, 'a', 'b', x);
        }

        return res;
    }
    
    int removePair(string &s, char first, char second, int score) {
        stack<char> st;
        int count = 0;

        string next_pass;
        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                count++;
            } else {
                st.push(ch);
            }
        }

        s.clear();
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());

        return count * score;
    }
};
