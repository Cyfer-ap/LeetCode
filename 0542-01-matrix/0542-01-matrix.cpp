class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
                else{
                    result[i][j] = INT_MAX;
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1,0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(auto& dir : dirs){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(result[nrow][ncol] > result[row][col] + 1){
                        result[nrow][ncol] = result[row][col]+1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return result;
    }
};