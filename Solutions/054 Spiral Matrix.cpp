class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;   

        int x = 0, y = 0;
        int len[4], n = matrix.size(), m = matrix[0].size();
        int change[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        len[0] = m;
        len[1] = n - 1;
        len[2] = m - 1;
        len[3] = n - 2;

        while(ans.size() < n * m){
            for (int i = 0; i < 4 && ans.size() < n * m; i++){
                for (int j = 0; j < len[i]; j++){
                    ans.push_back(matrix[x][y]);
                    x += change[i][0];
                    y += change[i][1];
                }
                len[i] -= 2;
                x -= change[i][0];
                y -= change[i][1];
                x += change[(i + 1) % 4][0];
                y += change[(i + 1) % 4][1];
            }
        }

        return ans;
    }
};