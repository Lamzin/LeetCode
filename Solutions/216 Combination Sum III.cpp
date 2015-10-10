class Solution {
public:
    vector<vector<int>> combinationSum3(int count, int target) {
        if (count == 0) return vector<vector<int>>();
        
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<vector<int>> result;
        vector<int> current(1, candidates[0]), index(1, 0);
        int current_sum = candidates[0];

        while(current.size()){
            if (current_sum == target && current.size() == count) result.push_back(current);

            if (index.back() + 1 < candidates.size() && current_sum + candidates[index.back() + 1] <= target){
                current_sum += candidates[index.back() + 1];
                current.push_back(candidates[index.back() + 1]);
                index.push_back(index.back() + 1);
            }
            else{
                while(current.size() && (index.back() + 1 >= candidates.size() || current_sum + (candidates[index.back() + 1] - current.back()) > target)){
                    current_sum -= current.back();
                    current.pop_back();
                    index.pop_back();
                }

                if (current.size()){
                    current_sum   += candidates[index.back() + 1] - current.back();
                    current.back() = candidates[index.back() + 1];
                    index.back()   = index.back() + 1;
                }
            }

        }

        return result;
    }
};