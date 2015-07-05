class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x, y, tmp, xx, yy;

        for (int i = 0; i < n; i++){
            for (int j = i + 1; i + j < n; j++)
            {
                x = xx = i;
                y = yy = j;
                tmp = matrix[x][y];
                for (int k = 0; k < 4; k++){
                    xx = y;
                    yy = n - 1 - x;
                    x = xx;
                    y = yy;
                    swap(tmp, matrix[x][y]);
                }
            }
        }

    }
};