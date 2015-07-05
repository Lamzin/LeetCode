class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0, pow = 1; i < 32; i++, pow*=2){
            if ((1 << i) & m && m % pow + n - m < pow)
                ans |= pow;
        }
        return ans;        
    }
};