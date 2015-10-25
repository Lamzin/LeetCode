class Solution {
private:
    int n, m;
    vector<vector<int>> *Board;
    int will_live[6] = {0, 1, 0, 1, 0, 1};
    int was_live[6] = {0, 1, 0, 0, 1, 1};
    int go[2][2] = {{2, 3}, {4, 5}};


    int alive(int x, int y){
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        return was_live[(*Board)[x][y]];
    }

    int count_alive_neighbours(int x, int y){
        int ans = 0;
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
                if (i || j) ans += alive(x + i, y + j);
        return ans;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        Board = &board;
        n = Board->size();
        if (Board->size()) m = (*Board)[0].size();
        else return;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int neighbours_alive = count_alive_neighbours(i, j);
                if (board[i][j]){
                    board[i][j] = (neighbours_alive == 2 || neighbours_alive == 3) ? go[1][1] : go[1][0];
                }
                else{
                    board[i][j] = (neighbours_alive == 3) ? go[0][1] : go[0][0];
                }

            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                board[i][j] = will_live[board[i][j]];
            }
        }

    }
};