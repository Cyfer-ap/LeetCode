class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> seen;
        unordered_set<int> curr;

        for(int num : arr){
            unordered_set<int> next;
            next.insert(num);
            for(int val : curr){
                next.insert(val | num);
            }
            curr = next;
            seen.insert(curr.begin(), curr.end());
        }
        return seen.size();
    }
};