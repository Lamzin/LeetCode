class Solution {
private:
    int result;
    vector<string> template_queens;
    vector<int> current, used, used_n;
    int N, next_index, last_index;

    void fill(int numb, int val){
        int x = numb / N, y = numb % N;
        used_n[y] = val;

        for (int ii = -1; ii < 2; ii++)
        for (int jj = -1; jj < 2; jj++)
        if (ii || jj)
        for (int xx = x, yy = y; xx >= 0 && xx < N && yy >= 0 && yy < N; xx += ii, yy += jj)
            used[xx * N + yy] += val;
    }


    bool next_exist(int pos = 0){
        for (int i = pos; i < N; i++)
            if (used_n[i] == -1 && used[current.size() * N + i] == 0){
                next_index = i;
                return true;
            }

        return false;
    }


public:
    int totalNQueens(int n) {
        if (n <= 0) return result;

        N = n;
        template_queens.resize(n, string(n, '.'));
        used.resize(n * n, 0);
        used_n.resize(n, -1);

        current.push_back(0);
        fill(0, 1);

        while (current.size()){
            if (current.size() == n){
                result++;
            }

            if (next_exist()){
                fill(current.size() * N + next_index, 1);
                current.push_back(next_index);
            }
            else{
                
                do
                {
                    last_index = current.back();
                    current.pop_back();
                    fill(current.size() * n + last_index, -1);

                    if (next_exist(last_index + 1)){
                        fill(current.size() * n + next_index, 1);
                        current.push_back(next_index);
                        break;
                    }
                    else{

                    }

                } while (current.size());

            }

        }

        return result;
    }
};