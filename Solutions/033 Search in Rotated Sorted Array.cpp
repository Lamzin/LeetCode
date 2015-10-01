class Solution {
private:
    int search_sorted(vector<int>& nums, int target, int left, int right){
        int m;
        while(left < right){
            m = left + (right - left) / 2;

            if (nums[m] < target){
                left = m + 1;
            }
            else{
                right = m;
            }
        }

        return (nums[right] == target) ? right : -1;
    }


public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return -1;
        }

        if (nums[0] < nums[nums.size() - 1]){
            return search_sorted(nums, target, 0, nums.size() - 1);
        }
        else{

            int l = 0, r = nums.size() - 1, m;
            while(l < r){
                m = l + (r - l) / 2;
                if (nums[0] <= nums[m]){
                    l = m + 1;
                }
                else{
                    r = m;
                }
            }

            if (nums[0] <= target){
                return search_sorted(nums, target, 0, max(0, r - 1));
            }
            else{
                return search_sorted(nums, target, r, nums.size() - 1);
            }

        }

    }
};