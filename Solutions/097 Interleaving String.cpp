class Solution {
private:
    vector<vector<int>> dp;
    string *ss1, *ss2, *ss3;

    bool dinamic(int x, int y) {
        int &__dp = dp[x][y];
        if (__dp != -1) return __dp;
        if (x + y == ss3->length()) return __dp = true;

        bool result = false;
        if (x < ss1->length() && ss1->at(x) == ss3->at(x + y)) result |= dinamic(x + 1, y);
        if (y < ss2->length() && ss2->at(y) == ss3->at(x + y)) result |= dinamic(x, y + 1);

        return __dp = result;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        ss1 = &s1;
        ss2 = &s2;
        ss3 = &s3;

        dp.resize(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return dinamic(0, 0);
    }
};