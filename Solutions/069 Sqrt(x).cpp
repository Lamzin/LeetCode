class Solution {
public:
    int sqrt(int x) {
        int l=1, r=x, m;
        while(l<r){
            m = (l+r+1)/2;
            if (m > x/m) r = m-1;
            else l = m;
        }
        return r;
    }
};