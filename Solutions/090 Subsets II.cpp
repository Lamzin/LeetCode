class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int k = 0; k <= nums.size(); k++){
            vector<int> current(k), index(k);

            for (int i = 0; i < k; i++) index[i] = i;

            bool next = true;
            while(next){
                for (int i = 0; i < k; i++) current[i] = nums[index[i]];
                result.push_back(current);
                next = false;

                for(int i = k - 1; i >= 0; i--){
                    if (k - i + index[i] < nums.size() && nums[index[i]] < nums[index[i] + 1]){
                        next = true;
                        index[i]++;
                        
                        for (int j = i + 1; j < k; j++){
                            index[j] = index[j - 1] + 1;
                        }

                        break;
                    }
                    else if (index[i] + 1 < nums.size() && nums[index[i]] == nums[index[i] + 1]){
                        index[i]++;
                        i = k;
                    }
                }

            }

        }    

        return result;
    }
};