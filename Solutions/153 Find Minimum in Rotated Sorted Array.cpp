class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;

        while(l <= r){
            if (nums[l] <= nums[r]) return nums[l];

            m = (l + r) / 2;
            if (nums[l] < nums[m])
                l = m;
            else if (nums[l] > nums[m])
                r = m;
            else 
                return min(nums[l], nums[r]);
        }
        return nums[l];
    }
};