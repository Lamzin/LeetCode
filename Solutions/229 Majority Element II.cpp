class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int count_y = 0, count_z = 0, y = 0, z = 1;

        for (auto x = nums.begin(); x != nums.end(); x++){
            if (*x == y) count_y++;
            else if (*x == z) count_z++;
            else if (count_y == 0) y = *x, count_y++;
            else if (count_z == 0) z = *x, count_z++;
            else{
                count_y--;
                count_z--;
            }
        }        
        
        count_y = count_z = 0;
        for (auto x = nums.begin(); x != nums.end(); x++){
            if (*x == y) count_y++;
            if (*x == z) count_z++;
        }

        if (count_y > nums.size() / 3) result.push_back(y);
        if (count_z > nums.size() / 3) result.push_back(z);
        return result;
    }
};