class Solution {
private:
  int column[9][9], row[9][9], square[3][3][9], lock[9][9], next_value;

  void fill(int position, int value, int used){
    int x = position / 9, y = position % 9;
    if (lock[x][y] != -1) return;
    row[x][value] = column[y][value] = square[x / 3][y / 3][value] = used;
  }

  bool check_add(int position, int start_from = 0){
    int x = position / 9, y = position % 9;
    next_value = -1; // If answer = false -> next_value = -1
    if (lock[x][y] != -1){
      if (lock[x][y] >= start_from) next_value = lock[x][y];
      return lock[x][y] >= start_from;
    }

    for (int i = start_from; i < 9; i++)
      if (!row[x][i] && !column[y][i] && !square[x / 3][y / 3][i]){
        next_value = i;
        return true;
      }
    return false;
  }

public:
  void solveSudoku(vector<vector<char>>& board) {
    vector<int> current;

    for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) column[i][j] = row[i][j] = 0;

    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    for (int g = 0; g < 9; g++) square[i][j][g] = 0;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.') lock[i][j] = -1;
            else{
                int tmp = lock[i][j] = board[i][j] - '1';
                row[i][tmp] = column[j][lock[i][j]] = square[i / 3][j / 3][lock[i][j]] = 1;
            }

    current.push_back((lock[0][0] != -1) ? board[0][0] - '1' : 0);
    fill(0, current[0], 1);

    while (current.size()){
      if (current.size() == 81) break;

      if (check_add(current.size())){
        fill(current.size(), next_value, 1);
        current.push_back(next_value);
      }
      else{

        do{
          if (current.size()){
            next_value = current.back();
            current.pop_back();
            fill(current.size(), next_value, 0);
          }
          else break;
        } while (!check_add(current.size(), next_value + 1));

        if (next_value != -1){
          fill(current.size(), next_value, 1);
          current.push_back(next_value);
        }
      }
    }

    if (current.size() == 81)
    for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      board[i][j] = current[i * 9 + j] + '1';
  }
};