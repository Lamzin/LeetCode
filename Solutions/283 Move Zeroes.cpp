class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) cnt++;
            else nums[i - cnt] = nums[i];
        }        
        for (int i = nums.size() - cnt; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};