class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        long long best = 0;
        while(l<r){
            long long w = r-l;
            long long h = min(height[l], height[r]);
            best = max(best, w*h);
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return best;
    }
};