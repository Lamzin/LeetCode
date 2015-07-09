class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> C(n, vector<int>(m));      

        for (int i = 0; i < n; i++) C[i][0] = 1;
        for (int i = 0; i < m; i++) C[0][i] = 1;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                C[i][j] = C[i - 1][j] + C[i][j - 1];

        return C[n - 1][m - 1];
    }
};