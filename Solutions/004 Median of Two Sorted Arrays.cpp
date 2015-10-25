class Solution {
private:
    int N, M, count_before_median;
    double median = 0.0f;

    void findMedian(vector<int>& nums1, vector<int>& nums2){
        int left, right, middle, l = 0, r = 0, m = 0;
        left = 0;
        right = nums1.size() - 1;

        while (left < right){
            middle = left + (right - left) / 2;

            if (nums2.size() && nums2.back() < nums1[middle]) r = nums2.size();
            else if (nums2.size()){
                l = 0;
                r = nums2.size() - 1;
                while (l < r){
                    m = l + (r - l) / 2;
                    if (nums2[m] <= nums1[middle] && middle + m < count_before_median) l = m + 1;
                    else r = m;
                }
            }

            if (middle + r < count_before_median) left = middle + 1;
            else right = middle;
        }

        if (nums1.size() /*&& right == nums1.size() - 1*/){
            if (nums2.size() && nums2.back() < nums1[right]) r = nums2.size();
            else if (nums2.size()){
                l = 0;
                r = nums2.size() - 1;
                while (l < r){
                    m = l + (r - l) / 2;
                    if (nums2[m] <= nums1[right] && right + m < count_before_median) l = m + 1;
                    else r = m;
                }
                if (nums2[r] < nums1[right]) r = -100000;
            }
        }

        if (right + r == count_before_median){
            if (right < nums1.size()){
                median = nums1[right];
                if ((N + M) % 2 == 0){
                    if (right + 1 < nums1.size() && r < nums2.size()) median = (median + min(nums1[right + 1], nums2[r])) / 2.0;
                    else if (r < nums2.size()) median = (median + nums2[r]) / 2.0;
                    else if (right + 1 < nums1.size()) median = (median + nums1[right + 1]) / 2.0;
                }
            }
        }

    }


public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) return 0.0f;

        N = nums1.size();
        M = nums2.size();
        count_before_median = (N + M - 1) / 2;


        findMedian(nums1, nums2);
        findMedian(nums2, nums1);

        return median;
    }
};