class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0, lastbit;
        for (int i = 0; i < nums.size(); axorb ^= nums[i++]);

        for (lastbit = 1; !(lastbit & axorb); lastbit *= 2);
        // lastbit = (axorb & (axorb - 1)) ^ axorb;
        // lastbit = axorb & (-axorb);

        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] & lastbit) a ^= nums[i];
            else b ^= nums[i];
        }

        return vector<int>{a,b};
    }
};