class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int lower_index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lower_index >= 0 && lower_index < nums.size() && nums[lower_index] == target){
            ans.push_back(lower_index);
            ans.push_back(upper_bound(nums.begin(), nums.end(), target) - 1 - nums.begin());
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};