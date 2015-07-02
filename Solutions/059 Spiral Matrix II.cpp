class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int i = 0, j = 0;
        
        for (int cnt = 1, direction = 0; cnt <= n*n;){
            if (direction == 0){
                for (; j < n && ans[i][j] == 0; j++) ans[i][j] = cnt++;
                j--;
                i++;
            }
            else if (direction == 1){
                for (; i < n && ans[i][j] == 0; i++) ans[i][j] = cnt++;
                i--;
                j--;
            }
            else if (direction == 2){
                for (; j >= 0 && ans[i][j] == 0; j--) ans[i][j] = cnt++;
                j++;
                i--;
            }
            else if (direction == 3){
                for (; i >= 0 && ans[i][j] == 0; i--) ans[i][j] = cnt++;
                i++;
                j++;
            }
            direction = (direction + 1) % 4;
        }
        
        return ans;
    }
};