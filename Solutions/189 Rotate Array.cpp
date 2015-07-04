class Solution {
protected:
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }

public:
    void rotate(vector<int>& nums, int k) {
        int count = gcd((int)nums.size(), k);

        int tmp, index;
        for (int cnt = 0; cnt < count; cnt++){
            index = (cnt + k) % nums.size();
            tmp = nums[cnt];
            while(index != cnt){
                swap(tmp, nums[index]);
                index = (index + k) % nums.size();
            }
            nums[cnt] = tmp;
        }
    }
};