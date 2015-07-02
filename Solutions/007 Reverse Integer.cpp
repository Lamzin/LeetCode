class Solution {
public:
    int reverse(int x) {
        long long ans = 0, X = abs((long long)x);
        bool minus = x < 0;
        
        while(X){
            ans = ans * 10 + X % 10;
            X /= 10;
        }
        if (ans > ((long long)1 << 31)) return 0;
        
        if (minus) ans*=-1;
        return ans;
    }
};