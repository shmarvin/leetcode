// 598. Range Addition II
// https://leetcode.com/problems/range-addition-ii/
// Difficulty: Easy

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        /*
        Every operation hits 0,0
        The rect that is the intersection of all rectangles is the answer.
        */
        for (vector<int>& v : ops) {
            if (v[0] < m) m = v[0];
            if (v[1] < n) n = v[1];
        }
        return m * n;
    }
};