class Solution {
private:
    int n, m;
    vector<vector<char>> *Board;

    bool check(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m && (*Board)[x][y] == 'O';
    }

    void bfs(int x, int y){
        vector<pair<int, int>> que;
        que.push_back(make_pair(x, y));
        (*Board)[x][y] = 'Y';

        int current = 0;
        while(current < que.size()){
            x = que[current].first;
            y = que[current].second;
            if (check(x + 1, y)) que.push_back(make_pair(x + 1, y)), (*Board)[x + 1][y] = 'Y';
            if (check(x - 1, y)) que.push_back(make_pair(x - 1, y)), (*Board)[x - 1][y] = 'Y';
            if (check(x, y + 1)) que.push_back(make_pair(x, y + 1)), (*Board)[x][y + 1] = 'Y';
            if (check(x, y - 1)) que.push_back(make_pair(x, y - 1)), (*Board)[x][y - 1] = 'Y';
            current++;
        }
    }


public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        Board = &board;

        for (int i = 0; i < n; i++){
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][m - 1] == 'O') bfs(i, m - 1);
        }

        for (int j = 0; j < m; j++){
            if (board[0][j] == 'O') bfs(0, j);
            if (board[n - 1][j] == 'O') bfs(n - 1, j);
        }


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';

    }
};