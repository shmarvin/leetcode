// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium

class Solution {
    static bool interval_sort(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        perhaps a sort by its starting or ending interval time would be useful,
        - two overlapping intervals must overlap with all between them
        - to check for overlapping, travel to the right until the end time is no longer >= the start time. then start from whatever interval you are on and do the same thing. When you end, that becomes an interval.
        */

        std::sort(intervals.begin(), intervals.end(), interval_sort);

        vector<vector<int>> ans;

        int start_int = intervals[0][0];
        int end_int = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i) {

            int val_1 = intervals[i][0];
            int val_2 = intervals[i][1];

            if(end_int >= val_1) {
                end_int = max(end_int, val_2);
            } else {
                // write to the answer array
                ans.push_back({start_int, end_int});
                start_int = val_1;
                end_int = val_2;
            }
        }

        // At the very end, write to the answer array
        ans.push_back({start_int, end_int});

        return ans;
    }
};