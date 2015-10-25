class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;

        vector<int> current(triangle.size(), 0), next(triangle.size(), 0);
        current[0] = triangle[0][0];
        for (int level = 1; level < triangle.size(); level++){
            next[level] = triangle[level][level] + current[level - 1];
            next[0] = triangle[level][0] + current[0];
            for (int i = 1; i < level; i++) 
                next[i] = triangle[level][i] + min(current[i - 1], current[i]);
            current.swap(next);
        }        

        int result = current[0];
        for (int i = 1; i < current.size(); i++) result = min(result, current[i]);
        return result;
    }
};