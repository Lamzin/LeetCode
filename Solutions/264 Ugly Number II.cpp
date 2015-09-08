class Solution {
public:
    int nthUglyNumber(int n){
        set <long> prior{1};
        long cur = 1;
        while(n--){
            cur = *prior.begin();
            prior.erase(prior.begin());

            prior.insert(cur * 2);
            prior.insert(cur * 3);
            prior.insert(cur * 5);
        }
        return cur;
    }
};