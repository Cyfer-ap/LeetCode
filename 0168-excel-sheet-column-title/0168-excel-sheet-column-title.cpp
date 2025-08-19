class Solution {
public:
    string convertToTitle(int columnNumber) {
        int count = 0;
        string res;
        while(columnNumber > 0){
            columnNumber--;
            int r = columnNumber % 26;
            res.push_back('A'+r);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};