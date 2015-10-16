class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;

        while(left + 1 < nums.size() && nums[0] == nums[left + 1]) left++;
        while(right - 1 >= 0 && nums[nums.size() - 1] == nums[right - 1]) right--;

        while(left < right){
            middle = left + (right - left) / 2;
            if (nums[0] <= nums[middle]) left = middle + 1;
            else right = middle;
        }

        return min(nums[0], nums[right]);
    }
};