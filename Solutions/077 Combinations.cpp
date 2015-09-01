class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n == 0 || k == 0) return result;

        vector<int> current(k, -1);
        for (int i = 0; i < k; i++) current[i] = i + 1;
        result.push_back(current);

        bool next = true;
        while(next){
            next = false;

            for (int i = k - 1; i >= 0; i--){
                if (k - i + current[i] - 1 < n){
                    next = true;
                    current[i]++;
                    for (int j = i + 1; j < k; j++) current[j] = current[j - 1] + 1;
                    result.push_back(current);
                    break;
                }
            }
        }

        return result;
    }
};