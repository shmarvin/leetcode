// 624. Maximum Distance in Arrays
// https://leetcode.com/problems/maximum-distance-in-arrays/
// Difficulty: Medium

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        /*
        Avoid tracking second place values: calculate ans as you go
        - only use either first or last, not both!

        Track: min and max val EVER ENCOUNTERED, and max ans
        ans not necessarily max-min. max and min used to find even bigger answers.

        ans at any i is equal to biggest gap SO FAR from different segments.
        */


        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int ans = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            int firstVal = arrays[i][0];
            int backVal = arrays[i].back();

            ans = max(ans, max(backVal - minVal, maxVal - firstVal));
            minVal = min(minVal, firstVal);
            maxVal = max(maxVal, backVal);
        }

        return ans;





        // /*
        // Find the absolute min and absolute max,
        // but must be in different arrays.
        
        // Arrays are sorted

        // Just take top 2 min and top 2 max, s.t. 1 and 2 in diff arrays.
        // */
        // int ind_min = -1, ind_max = -1;
        // int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;

        // for(int i = 0; i < arrays.size(); ++i) {
        //     vector<int>& v = arrays[i];
        //     if (v[0] < min1) {
        //         min2 = min1;
        //         min1 = v[0];
        //         ind_min = i;
        //     } else if (v[0] < min2) {
        //         min2 = v[0];
        //     }
        //     if(v.back() > max1) {
        //         max2 = max1;
        //         max1 = v.back();
        //         ind_max = i;
        //     } else if (v.back() > max2){
        //         max2 = v.back();
        //     }
        // }

        // if (ind_min == ind_max) {
        //     return max (max1 - min2, max2 - min1);
        // }
        // return max1-min1;
    }
};