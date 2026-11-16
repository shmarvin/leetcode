// 135. Candy
// https://leetcode.com/problems/candy/
// Difficulty: Hard

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        RULES:
        Each child must have one candy
        A child rated higher than a neighbor must have more candy than that neighbor.
        Return minimum number of candies to satisfy conditions.
        
        Idea:
        The problem is a series of slopes.
        The tricky part is to handle peaks. The peak value must continue from the greater of the left/right slopes that form it.

        Tricky edge cases I dealt with:
        - Same number repeated.
        Errors fixed:
        - Descending into repeated numbers: added slope too many times.
        - Ascending into repeated numbers: failed to add slope at all
        */

        if (ratings.size() == 1) return 1;

        int candies = ratings.size();
        int prev_incr_streak = 0;
        int streak = 1;

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) { // ASCENDING
                if (i == ratings.size()-1) {
                    candies += streak;
                } else if (ratings[i] >= ratings[i+1]) {
                    // LOCAL PEAK
                    // Do not add. wait till we can calculate greater side
                    prev_incr_streak = streak;
                    streak = 1;
                } else {
                    candies += streak;
                    ++streak;
                }
            } else if (ratings[i] < ratings[i-1]) { // DESCENDING
                if (i == ratings.size()-1 || ratings[i] <= ratings[i+1]) {
                    // LOCAL MINIMUM
                    candies += max(streak, prev_incr_streak);
                    streak = 1;
                    prev_incr_streak = 0;
                } else {
                    candies += streak;
                    ++streak;
                }
            } else { // equal.
                if (prev_incr_streak > 0) {
                    candies += prev_incr_streak;
                    prev_incr_streak = 0;
                }
                streak = 1;
            }
        }
        return candies;
    }
};