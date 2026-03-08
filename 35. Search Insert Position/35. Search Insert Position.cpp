/*
 * Problem: 35. Search Insert Position
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/search-insert-position/submissions/1941712510/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
