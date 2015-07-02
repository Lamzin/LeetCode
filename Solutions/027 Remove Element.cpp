class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto tmp = new vector<int>;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val) tmp->push_back(nums[i]);
        
        nums = *tmp;
        return tmp->size();
    }
};