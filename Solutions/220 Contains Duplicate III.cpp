class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> record;
        
        for(int i = 0; i < nums.size(); i++){
            if (i > k) record.erase(nums[i - k - 1]);
            
            auto lower = record.lower_bound(nums[i] - t);
            if (lower != record.end() && abs(nums[i] - *lower) <= t) 
                return true;
            
            record.insert(nums[i]);
        }
        return false;
    }
};