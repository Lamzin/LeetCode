class Solution {
private:
    vector<vector<int>> dp;
    string *ss, *pp;
    int ss_len, pp_len;

    bool isMatch(int x, int y){
        if (x > ss_len || y > pp_len) return false;

        int &__dp__ = dp[x][y];
        if (__dp__ != -1) return __dp__;

        bool ans = false;

        if (y + 1 < pp_len && pp->at(y + 1) == '*'){
            ans |= isMatch(x, y + 2);
            if (x < ss_len && ss->at(x) == pp->at(y) || pp->at(y) == '.') 
                ans |= isMatch(x + 1, y + 2) | isMatch(x + 1, y);
        }
        else if (x < ss_len && y < pp_len){
            if (ss->at(x) == pp->at(y) || pp->at(y) == '.') ans |= isMatch(x + 1, y + 1);
        }

        return __dp__ = ans;
    }

public:
    bool isMatch(string s, string p) {
        ss = &s;
        pp = &p;
        ss_len = s.length();
        pp_len = p.length();
        dp.resize(ss_len + 1, vector<int>(pp_len + 1, -1));

        for (int i = 0; i < ss_len + 1; i++) dp[i][pp_len] = false;
        //for (int i = 0; i < pp_len + 1; i++) dp[ss_len][i] = false;
        dp[ss_len][pp_len] = true;

        return isMatch(0, 0);
    }
};