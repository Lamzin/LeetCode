class Solution {
    vector<vector<int>> matrix, current;
    int n, m, new_value, fir, sec;

    bool check(int start){
        current[0][0] = matrix[0][0] + start;
        if (current[0][0] <= 0) current[0][0] = -1;

        for (int i = 1; i < n; i++){
            new_value = current[i - 1][0] + matrix[i][0];
            current[i][0] = (current[i - 1][0] == -1 || new_value <= 0) ? -1 : new_value;
        }

        for (int i = 1; i < m; i++){
            new_value = current[0][i - 1] + matrix[0][i];
            current[0][i] = (current[0][i - 1] == -1 || new_value <= 0) ? -1 : new_value;
        }

        for (int i = 1; i < n; i++)
            for(int j = 1; j < m; j++){
                fir = (current[i - 1][j] == -1) ? -1 : current[i - 1][j] + matrix[i][j];
                sec = (current[i][j - 1] == -1) ? -1 : current[i][j - 1] + matrix[i][j];

                current[i][j] = max(fir, sec);
                if (current[i][j] <= 0) current[i][j] = -1;
            }

        return current[n - 1][m - 1] != -1;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        matrix = current = dungeon;

        int l = 1, r = 536870912, m;
        this->n = matrix.size();
        this->m = matrix[0].size();

        while(l < r){
            m = (l + r) / 2;

            if (check(m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};