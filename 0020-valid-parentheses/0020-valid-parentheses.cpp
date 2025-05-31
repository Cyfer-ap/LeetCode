class Solution {
public:
    
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s){
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);

            else{
                if(st.empty() || st.top() != bMap[ch]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};