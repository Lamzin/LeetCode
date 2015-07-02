class Solution {
public:
    int lengthOfLastWord(const char *s) {
        bool world = false;
        int len = 0;
        for (int i = 0; s[i]; i++){
            if (s[i] == ' ') world = false;
            else if (world == false){
                len = 1; 
                world = true;
            }
            else {
                len++;
                world = true;
            }
        }
        return len;
    }
};