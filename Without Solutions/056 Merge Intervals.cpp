/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
protected:
    static bool cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;

        if (intervals.size()){
            result.push_back(intervals[0]);
        }

        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i].start <= result[result.size() - 1].end){
                result[result.size() - 1].end = max(result[result.size() - 1].end, intervals[i].end);
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
