class Solution {
protected:
    bool ans;
    int n, m;
    string wrd;
    vector<vector<int>> arr;
    vector<vector<char>> brd;


    bool check(int x, int y, int len){
        return x >= 0 && x < n && y >= 0 && y < m && brd[x][y] == wrd[len] && !arr[x][y];
    }


    void dfs(int x, int y, int len){
        if (len + 1 == wrd.length()){
            ans = true;
            return;
        }  

        arr[x][y] = 1;

        if (!ans && check(x + 1, y, len + 1)) dfs(x + 1, y, len + 1);
        if (!ans && check(x - 1, y, len + 1)) dfs(x - 1, y, len + 1);
        if (!ans && check(x, y + 1, len + 1)) dfs(x, y + 1, len + 1);
        if (!ans && check(x, y - 1, len + 1)) dfs(x, y - 1, len + 1);

        arr[x][y] = 0;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {
        ans = false;
        wrd = word;

        n = board.size();
        if (n == 0){
            return false;
        }

        m = board[0].size();
        if (m == 0){
            return false;
        }

        arr = vector<vector<int>>(n, vector<int>(m, 0));
        brd = board;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0]) dfs(i, j, 0);
                if (ans) return true;
            }
        }

        return false;
    }
};