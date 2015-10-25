class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        if (nums[0] == target) return true;


        int l = 0, r = nums.size() - 1, m;

        while(l + 1 < nums.size() && nums[l + 1] == nums[0]) l++;
        while(r > l && nums[r] == nums[0]) r--;

        while(l < r){
            m = l + (r - l) / 2;
            if (nums[0] <= nums[m]) l = m + 1;
            else r = m;
        

        if (nums[0] < target){
            if (nums[0] > nums[r]) r--; 
            l = 0;
        }
        else{
            l = r;
            r = nums.size() - 1;
        }


        while(l < r){
            m = l + (r - l) / 2;
            if (target > nums[m]) l = m + 1;
            else r = m; 
        }


        return nums[r] == target;
    }
};