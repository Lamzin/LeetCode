class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int factorial[] = {1, 1, 1, 2, 6, 24, 120, 720, 720*7, 720*7*8, 720*7*8*9};
        int used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        string ans;
        for (int i = n, j; i > 0; i--){
            int cnt = k / factorial[i] + 1;
            k %= factorial[i];
            for (j = 1; cnt && j < 10; j++){
                if (!used[j]) cnt--;
            }
            j--;
            used[j] = 1;
            ans += j + 48;
        }

        return ans;
    }
};