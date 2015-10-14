class Solution {
public:
    string shortestPalindrome(string s) {
        string current = s;
        reverse(current.begin(), current.end());
        if (s == current) return s;
        current = s + "#" + current;

        int *pi = new int[current.length()], index, pi_max = 0;
        pi[0] = 0;

        for (int i = 1; i < current.length(); i++){
            index = pi[i - 1];
            while(index > 0 && current[i] != current[index]) index = pi[index - 1];
            pi[i] = index + (current[index] == current[i]);
        }
        pi_max = pi[current.length() - 1];

        current = s.substr(pi_max, s.length() - pi_max);
        reverse(current.begin(), current.end());

        return current + s;
    }
};