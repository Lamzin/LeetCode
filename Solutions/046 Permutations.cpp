class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end());
        bool next = true;
        int index;
        
        while(next){
            ans.push_back(nums);
            
            next = false;
            for (int i = nums.size() - 1; i; i--){
                if (nums[i - 1] < nums[i]){
                    index = i;
                    next = true;
                    for (int j = i + 1; j < nums.size(); j++){
                        if (nums[j] < nums[index] && nums[i - 1] < nums[j]) index = j;
                    }
                    swap(nums[index], nums[i - 1]);
                    sort(nums.begin() + i, nums.end());
                    
                    break;
                }
            }
        }
        
        return ans;
    }
};