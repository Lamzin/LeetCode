class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int left = 0, right = matrix.size() - 1, middle;
        int n = matrix.size(), m = matrix[0].size();
        while(left < right){
            middle = left + (right - left) / 2;
            if (matrix[middle][m - 1] < target) left = middle + 1;
            else right = middle;
        }

        int line = right;
        left = 0;
        right = matrix[line].size() - 1;

        while(left < right){
            middle = left + (right - left) / 2;
            if (matrix[line][middle] < target) left = middle + 1;
            else right = middle;
        }

        if (right < 0) return false;
        return matrix[line][right] == target;
    }
};