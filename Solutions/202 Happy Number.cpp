class Solution {
public:
    bool isHappy(int n) {
        int tmp = n, tmp2;
        
        int cnt = 0;
        do{
            if (tmp == 1) return true;
            tmp2 = 0;
            while(tmp){
                tmp2 += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            tmp = tmp2;
            if (cnt++ > 100) return false;
        }while(tmp != n);
        
        return false;
    }
};