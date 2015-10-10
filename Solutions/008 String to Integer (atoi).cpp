class Solution {
private:

    string __INT_MIN = "2147483648";
    string __INT_MAX = "2147483647";

    bool biger(string a, string b){
        return (a.length() != b.length()) ? (a.length() > b.length()) : a >= b;
    }

public:
    int myAtoi(string str) {
        if (str == "") return 0;

        string num;
        int i = 0, ans = 0, sign = 1;

        while(str[i] == ' ' && i < str.length()) i++;
        if (str[i] == '+') i++;
        else if (str[i] == '-'){
            sign = -1;
            i++;
        }
        while(i < str.length() && str[i] >= '0' && str[i] <= '9') num += str[i++];

        if (sign ==  1 && biger(num, __INT_MAX)) return 2147483647;
        if (sign == -1 && biger(num, __INT_MIN)) return -2147483648;
        if (num.length() == 0) return 0;

        i = 0;
        for (; i < num.length(); i++){
            ans = ans * 10 + num[i] - 48;
        }

        return sign * ans;
    }
};