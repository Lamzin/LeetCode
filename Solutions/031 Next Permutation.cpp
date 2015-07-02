class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, cur;
        for (i = nums.size() - 1; i>0; i--)
            if (nums[i - 1] < nums[i]) break;
        
        if (i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
         
        cur = i;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[j] < nums[cur] && nums[j] > nums[i - 1]) cur = j;
            
        swap(nums[i - 1], nums[cur]);
        sort(nums.begin() + i, nums.end());
    }
};