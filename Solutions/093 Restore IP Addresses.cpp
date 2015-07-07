class Solution {
protected:
    bool isValid(string &s){
        if (s.length() > 1 && s[0] == '0' || s.length() == 3 && s >= "256") return false;
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ss[4];

        int cnt[4];
        for (int i = 0; i <= 256; i++){
            int tmp = i;
            for (int j = 0; j < 4; j++){
                cnt[j] = tmp % 4;
                tmp /= 4;
            }

            if (cnt[0] * cnt[1] * cnt[2] * cnt[3] 
                && 
                cnt[0] + cnt[1] + cnt[2] + cnt[3] == s.length())
            {
                ss[0] = s.substr(0, cnt[0]);
                ss[1] = s.substr(cnt[0], cnt[1]);
                ss[2] = s.substr(cnt[0] + cnt[1], cnt[2]);
                ss[3] = s.substr(cnt[0] + cnt[1] + cnt[2], cnt[3]);

                if (   isValid(ss[0]) 
                    && isValid(ss[1]) 
                    && isValid(ss[2]) 
                    && isValid(ss[3]))
                {
                    ans.push_back(ss[0] + "." + ss[1] + "." + ss[2] + "." + ss[3]);
                }
            }
        }
        
        return ans;
    }
};