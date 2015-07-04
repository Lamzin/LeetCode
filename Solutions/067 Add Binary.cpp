class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.length() > b.length()) swap(a, b);

        string ans;    
        int nxt = 0;
        for (int i = 0; i < a.length(); i++){
            nxt = nxt + a[i] + b[i] - 96;
            ans += nxt % 2 + 48;
            nxt /= 2;
        }

        for (int i = a.length(); i < b.length(); i++){
            nxt = nxt + b[i] - 48;
            ans += nxt % 2 + 48;
            nxt /= 2;
        }

        while(nxt){
            ans += nxt % 2 + 48;
            nxt /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};