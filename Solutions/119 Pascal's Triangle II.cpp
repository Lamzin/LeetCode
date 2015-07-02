class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vect = {1};
        for (int i = 0; i<rowIndex; i++){
            vect.push_back(0);
            for (int i = vect.size()-1; i; i--) vect[i]+=vect[i-1];
        }
        return vect;
    }
};