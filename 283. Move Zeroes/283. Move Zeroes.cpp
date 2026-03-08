/*
 * Problem: 283. Move Zeroes
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/move-zeroes/submissions/1942283687/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) nums[slow++] = nums[fast];
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
