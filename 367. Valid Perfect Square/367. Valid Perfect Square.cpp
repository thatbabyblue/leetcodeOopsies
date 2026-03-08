/*
 * Problem: 367. Valid Perfect Square
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-perfect-square/submissions/1942223669/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid == num) return true;
            else if (mid * mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
