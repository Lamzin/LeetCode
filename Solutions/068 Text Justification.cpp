class Solution {
    string make_str(int l, int r, vector<string>& words, int maxWidth, int cur_len){
        int delta = maxWidth - cur_len;

        string ans = words[l];
        if (r - l == 0){
            for (int i = cur_len; i < maxWidth; i++) ans += ' ';
        }
        else if (r == words.size() - 1){
            delta = r - l;

            for (int i = l + 1, cnt = 0; i <= r; i++, cnt++){
                int _tmp_cnt =  delta / (r - l) + (cnt < delta % (r - l));
                for (int j = 0; j < _tmp_cnt; j++) ans += ' ';
                ans += words[i];
            }

            while(ans.length() != maxWidth) ans += ' ';
        }
        else{
            for (int i = l + 1, cnt = 0; i <= r; i++, cnt++){
                int _tmp_cnt =  delta / (r - l) + (cnt < delta % (r - l));
                for (int j = 0; j < _tmp_cnt; j++) ans += ' ';
                ans += words[i];
            }
        }

        return ans;
    }


public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.size() == 0) return result;

        int l = 0, r = 0, cur_len = words[0].length();

        for (int i = 1; i < words.size(); i++){
            if (cur_len + words[i].length() + i - l <= maxWidth){
                r = i;
                cur_len += words[i].length();
            }
            else{
                result.push_back(make_str(l, r, words, maxWidth, cur_len));
                l = r = i;
                cur_len = words[i].length();
            }
        }    
        result.push_back(make_str(l, r, words, maxWidth, cur_len));

        return result;
    }
};
