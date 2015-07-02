class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans = "";
        int code;
        
        while(n)
        {
            code = (n % 26) ? (n%26) : 26;
            n = (n - code) / 26;
            ans += code + 'A' - 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};