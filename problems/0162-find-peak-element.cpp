// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/
// Difficulty: Medium

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size());
    }

    // end exclusive
    int findPeakElement(vector<int>& nums, size_t start, size_t end) {
        int v_size = end-start;

        // Base Cases
        if(v_size == 1) return start;
        else if(v_size == 2) {
            if (nums[start] > nums[start + 1]) return start;
            else return start + 1;
        }


        size_t center_ind = start + (v_size-1)/2;
        bool greater_than_prev = nums[center_ind] > nums[center_ind-1];
        bool greater_than_next = nums[center_ind] > nums[center_ind+1];

        if (greater_than_prev) {
            if (greater_than_next) {
                return center_ind;
            } else {
                start = center_ind + 1;
            }
        } else {
            end = center_ind;
        }
        return findPeakElement(nums, start, end);
    }
};