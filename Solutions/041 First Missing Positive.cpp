class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= 0 || nums[i] > nums.size()) nums[i] = -1;
        }
        
        int cur, tmp;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != -1){
                cur = nums[i];
                while(cur > 0){
                    tmp = nums[cur - 1];
                    nums[cur - 1] = 0;
                    cur = tmp;
                }
                if (nums[i] != 0) nums[i] = -1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == -1) return i + 1;
        }
        return nums.size() + 1;
    }
};