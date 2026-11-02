// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// Difficulty: Easy

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        use a hashmap
        if map[target-num] exists, that's our solution (i of that number, and current i)
        map rather than set, because map points to its index.
        */
        unordered_map<int, int> m;
        
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            // if the perfect pair already in the map, return pair
            int& num = nums[i];
            if(m.count(target-num)) {
                return {i, m[target-num]};
            }
            m[num] = i;
        }
        return {-1, -1}; // should be impossible.
    }
};