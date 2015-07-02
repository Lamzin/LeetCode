class Solution {
public:
    int singleNumber(int A[], int n) {
        unsigned int res=0, tmp, tmp2, pow = 1;
        for (int i = 0; i<n; i++){
            tmp = res;
            tmp2 = A[i] + 1073741824;
            pow = 1;
            res = 0;
            while(tmp2 || tmp){
                res = res + pow*((tmp % 3 + tmp2 % 3) % 3);
                tmp2/=3;
                tmp/=3;
                pow*=3;
            }
        }
        return res-1073741824;
    }
};