class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int m = '0'-1;
        for(int i = 1; i < n-1; i++){
            if(num[i-1] == num[i]  && num[i] == num [i+1]){
                m = max(m, (int)num[i]);
            }
        }
        if(m<'0') return "";
        return string(3, m);
    }
};