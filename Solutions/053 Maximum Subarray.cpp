class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int cursum = 0, maxsum = nums[0];

        for (int i = 0; i < nums.size(); i++){
            cursum += nums[i];
            maxsum = max(maxsum, cursum);
            if (cursum < 0) cursum = 0;
        }
        
        return maxsum;
    }
};