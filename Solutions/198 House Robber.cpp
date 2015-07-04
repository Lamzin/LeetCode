class Solution {
protected:
    vector<int> dp, *num;
    int dinamic_programming(int index){
        if (index >= dp.size()) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(dinamic_programming(index + 1), dinamic_programming(index + 2) + (*num)[index]);
    }

public:
    int rob(vector<int>& nums) {
        num = &nums;
        dp.resize(nums.size(), -1);
        return dinamic_programming(0);
    }
};