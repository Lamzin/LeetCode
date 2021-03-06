class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int i = 0, j;
        
        for (j = 0; j < nums.size(); j++){
            while(j + 2 < nums.size() && nums[j + 2] == nums[j]) j++;
            
            nums[i++] = nums[j];
        }
        
        return i;
    }
};