class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++){
            vector<int> a(9), b(9);
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    int &param = a[board[i][j] - '1'];
                    if (param) return false;
                    param = 1;
                }
                if (board[j][i] != '.'){
                    int &param = b[board[j][i] - '1'];
                    if (param) return false;
                    param = 1;
                }
            }
        }
        
        for (int square = 0; square < 9; square++){
            vector<int> vect(9);
            for (int i = (square % 3)*3, cnt_i = 0; cnt_i < 3; cnt_i++, i++)
                for (int j = (square / 3)*3, cnt_j = 0; cnt_j < 3; cnt_j++, j++)
                    if (board[i][j] != '.'){
                        int &param = vect[board[i][j] - '1'];
                        if (param) return false;
                        param = 1;
                    }   
        }
        
        return true;
    }
};