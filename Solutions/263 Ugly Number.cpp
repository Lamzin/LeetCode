class Solution {
public:
    bool isUgly(int num) {
        int prime[] = {2, 3, 5};
        for (int i = 0; i < 3; i++)
            while(num % prime[i] == 0 && num) num /= prime[i];
        return num == 1;
    }
};