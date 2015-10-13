class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index, next;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                index = i;

                while(nums[index] > 0){
                    next = nums[index];
                    nums[index] = -1;
                    index = next;
                }
                if (i != index){
                    nums[index]--;
                    nums[i] = 0;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < -1) return i;
        }
        return 0;
    }
};


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         for (int i = 1; i < nums.size(); i++){
//             if (nums[i] == nums[i - 1]) return nums[i];
//         }
//         return 0;
//     }
// };