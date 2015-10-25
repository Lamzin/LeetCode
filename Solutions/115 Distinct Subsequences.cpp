class Solution {
private:
    vector<vector<int>> dp;
    string *ss, *tt;
    int ss_len, tt_len;

    int numDistinct(int x, int y){
        int &__dp__ = dp[x][y];
        if (__dp__ != -1) return __dp__;

        int ans = 0;
        ans += numDistinct(x + 1, y);
        if (ss->at(x) == tt->at(y)) ans += numDistinct(x + 1, y + 1);

        return __dp__ = ans;
    }


public:
    int numDistinct(string s, string t) {
        ss = &s;
        tt = &t;
        ss_len = s.length();
        tt_len = t.length();

        dp.resize(ss_len + 1, vector<int>(tt_len + 1, -1));

        for (int i = 0; i < tt_len + 1; i++) dp[ss_len][i] = 0;
        for (int i = 0; i < ss_len + 1; i++) dp[i][tt_len] = 1;
        //dp[ss_len][tt_len] = 1;

        return numDistinct(0, 0);
    }
};