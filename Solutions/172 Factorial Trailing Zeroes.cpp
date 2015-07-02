class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long pow = 5;
        while(pow <= n)
        {
            ans += n / pow;
            pow*=5;
        }
        return ans;
    }
};