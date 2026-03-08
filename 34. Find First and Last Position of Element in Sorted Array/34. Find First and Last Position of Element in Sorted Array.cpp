/*
 * Problem: 34. Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1942210061/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int getleftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                res = right;
            } else left = mid + 1;
        }
        return res;
    }
    int getrightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
                res = left;
            } else right = mid - 1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getleftBorder(nums, target);
        int rightBorder = getrightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        return {-1, -1};
    }
};
