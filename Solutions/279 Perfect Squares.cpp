class Solution {
private:
    map<int, int> dp;

    bool is_square(int n){
        int _sqrt = sqrt(n);
        for (int i = max(1, _sqrt - 2); i * i <= n; i++){
            if (i*i == n) return true;
        }
        return false;
    }

    int dinamic(int n, int k){
        if (dp.find(n) != dp.end()) return dp[n];
        
        if (is_square(n)) return dp[n] = 1;
        else if (k > 5) return 10000;
        else{
            int ans = 10000000;
            for (int i = max((int)sqrt(n / 2) - 3, 1); i*i <= n; i++) ans = min(ans, 1 + dinamic(n - i*i, k + 1));
            return dp[n] = ans;
        }
    }


public:
    int numSquares(int n){
        int ans = dinamic(n, 0);
        if (ans > 5) return -1;
        return ans;
    }
};