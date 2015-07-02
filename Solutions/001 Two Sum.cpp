class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        vector<pair<int, int> > vect(nums.size());
        for (int i = 0; i<nums.size(); i++) vect[i] = make_pair(nums[i], i);
        
        sort(vect.begin(), vect.end());
        sort(nums.begin(), nums.end());
        
        
        for (int i = 0; i < nums.size(); i++){
            if (2 * vect[i].first == target && i + 1 < vect.size() && vect[i].first == vect[i + 1].first){
                ans[0] = vect[i].second + 1;
                ans[1] = vect[i + 1].second + 1;
                sort(ans.begin(), ans.end());
                return ans;
            }
            
            auto lower = lower_bound(nums.begin(), nums.end(), target - nums[i]);
            if (lower != nums.end() && nums[i] + *lower == target){
                ans[0] = vect[i].second + 1;
                ans[1] = vect[lower - nums.begin()].second + 1;
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};