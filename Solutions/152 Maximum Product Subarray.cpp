class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int tmp[3], cur[2], ans;
        cur[0] = cur[1] = ans = nums[0];

        for (int i = 1; i < nums.size(); i++){
            tmp[0] = cur[0] * nums[i];
            tmp[1] = cur[1] * nums[i];
            tmp[2] = nums[i];
            sort(tmp, tmp + 3);

            cur[0] = tmp[0];
            cur[1] = tmp[2];
            ans = max(ans, cur[1]);
        }

        return ans;
    }
};