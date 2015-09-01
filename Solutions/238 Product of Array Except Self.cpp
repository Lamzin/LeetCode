class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0) return vector<int>();

        vector<int> result(nums.size(), 1);
        result[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--){
            result[i] = result[i + 1 ] * nums[i];
        }

        int current = 1;
        for (int i = 0; i < nums.size() - 1; i++){
            result[i] = current * result[i + 1];
            current *= nums[i];
        }
        result[nums.size() - 1] = current;

        return result;
    }
};