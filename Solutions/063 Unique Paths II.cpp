class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;

        for(int i = 0; i < n; i++){
            if (obstacleGrid[i][0] == 1) 
                break;
            else 
                obstacleGrid[i][0] = -1;
        }

        for(int i = 0; i < m; i++){
            if (obstacleGrid[0][i] == 1) 
                break;
            else 
                obstacleGrid[0][i] = -1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if (obstacleGrid[i][j] == 1) continue;

                if (obstacleGrid[i][j - 1] == 1 && obstacleGrid[i - 1][j] == 1){
                    obstacleGrid[i][j] = 1;
                }
                else if (obstacleGrid[i][j - 1] == 1){
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                }
                else if (obstacleGrid[i - 1][j] == 1){
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                }
                else{
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                }
            }
        }

        return (obstacleGrid[n - 1][m - 1] != 1) ? - obstacleGrid[n - 1][m - 1] : 0;
    }
};