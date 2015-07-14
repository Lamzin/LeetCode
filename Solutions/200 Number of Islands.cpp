class Solution {
protected:
    int n, m;
    vector<vector<char>> *mas;
    
    bool isValid(int x, int y){
        return x >=0 && x < n && y >= 0 && y < m && (*mas)[x][y] == '1';
    }

    void dfs(int x, int y){
        (*mas)[x][y] = '0';

        if (isValid(x - 1, y)) dfs(x - 1, y);
        if (isValid(x + 1, y)) dfs(x + 1, y);
        if (isValid(x, y - 1)) dfs(x, y - 1);
        if (isValid(x, y + 1)) dfs(x, y + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans;
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        mas = &grid;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                if ((*mas)[i][j] == '1'){
                    ans++;
                    dfs(i, j);
                }
        }

        return ans;
    }
};