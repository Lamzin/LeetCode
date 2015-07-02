class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0){
            x = 1 / x;
            n *= -1;
        }
        if (n == 0) return 1;
        double ans = 1, pow = x;
        
        while(n){
            if (n % 2 == 1) ans *= pow;
            pow *= pow;
            n/=2;
        }
        
        return ans;
    }
};