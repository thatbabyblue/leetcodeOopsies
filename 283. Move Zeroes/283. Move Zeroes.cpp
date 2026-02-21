/*
 * Problem: 283. Move Zeroes
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/move-zeroes/submissions/1925948316/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        for (; slow < nums.size(); slow++) {
            nums[slow] = 0;
        }
    }
};
