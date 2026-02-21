/*
 * Problem: 189. Rotate Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotate-array/submissions/1926681848/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
