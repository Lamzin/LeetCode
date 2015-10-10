class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return vector<vector<int>>();

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> current(1, candidates[0]), index(1, 0);
        int current_sum = candidates[0];

        while(current.size()){
            if (current_sum == target) result.push_back(current);

            if (current_sum + candidates[index.back()] <= target){
                current_sum += candidates[index.back()];
                current.push_back(candidates[index.back()]);
                index.push_back(index.back());
            }
            else{
                while(current.size() 
                    && 
                    (index.back() + 1 >= candidates.size() 
                        || current_sum + (candidates[index.back() + 1] - current.back()) > target))
                {
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