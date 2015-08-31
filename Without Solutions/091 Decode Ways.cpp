class Solution {
    vector<int> dp;
    string ss;

    int dinamic(int cur){
        if (dp[cur] != -1) return dp[cur];
        if (ss[cur] == '0') return 0;
        else{
            dp[cur] = dinamic(cur + 1);
            if (cur + 1 < ss.length() && (ss[cur] - 48) * 10 + ss[cur + 1] - 48 < 27) dp[cur] += dinamic(cur + 2);
            return dp[cur];
        }
    }

public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;

        dp.resize(s.length() + 1, -1);
        dp[s.length()] = 1;
        ss = s;

        return dinamic(0);
    }
};
