class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(numRows);

        int cr = 0;
        int gd = false;

        for(char c : s){
            rows[cr] += c;
            if(cr == 0 || cr == numRows - 1){
                gd = !gd;
            }
            cr += gd ? 1: -1;
        }

        string result;
        for(const string& row : rows){
            result += row;
        }
        return result;
    }
};