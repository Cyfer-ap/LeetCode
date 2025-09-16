class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(long long x : nums){
            st.push_back(x);
            while(st.size() >= 2){
                long long a = st[st.size() - 2];
                long long b = st.back();
                long long g = std::gcd(a,b);
                if(g == 1) break;

                long long l = (a/g)*b;
                st.pop_back();
                st.back() = l;
            }
        }
        return st;
    }
};