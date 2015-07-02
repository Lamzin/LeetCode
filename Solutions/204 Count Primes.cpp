class Solution {
public:
    int countPrimes(int n) {
        vector<int> simple(n, 0), primes;
        int i;
        
        for (i = 3; i*3 < n; i+=2){
            if (!simple[i]){
                simple[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n && simple[j] <= simple[i] ; j++){
                simple[i * primes[j]] = primes[j];
            }
        }
        
        if (2 < n) primes.push_back(2);
        for (; i < n; i+=2) 
            if (!simple[i]) primes.push_back(i);
        
        return primes.size();
    }
};