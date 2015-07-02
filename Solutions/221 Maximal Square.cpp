class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int> > vect(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++){
                vect[i][j] = matrix[i][j] - '0';
                if (i && j && vect[i][j]) vect[i][j] += min(vect[i - 1][j], min(vect[i][j - 1], vect[i - 1][j- 1]));
                ans = max(ans, vect[i][j]);
            }
        return ans*ans;
    }
};