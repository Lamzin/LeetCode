class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n, m, left, right, middle;

        if ((n = matrix.size()) == 0 || (m = matrix[0].size()) == 0) return false;

        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][0] > target || matrix[i][m - 1] < target) continue;

            left = 0;
            right = m - 1;

            while(left < right){
                middle = left + (right - left) / 2;
                if (matrix[i][middle] < target) left = middle + 1;
                else right = middle;
            }

            if (matrix[i][right] == target) return true;
        }        

        return false;
    }
};