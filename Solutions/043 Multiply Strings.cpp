class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "0";
    
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int nxt, index;
        
        for (int i = 0; i < num1.length(); i++)
            for (int j = 0; j < num2.length(); j++){
                nxt = (num1[i] - 48) * (num2[j] - 48);
                
                index = i + j;
                while (nxt){
                    while (ans.length() <= index) ans += "0";
                    nxt += ans[index] - 48;
                    ans[index] = nxt % 10 + 48;
                    nxt /= 10;
                    index++;
                }
            }
            
        reverse(ans.begin(), ans.end());
        return ans;
    }
};