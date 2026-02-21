/*
 * Problem: 34. Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1926704376/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid - 1;
            else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        return {-1, -1};
    }
};
