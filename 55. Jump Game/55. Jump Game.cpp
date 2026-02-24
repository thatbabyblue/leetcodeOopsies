/*
 * Problem: 55. Jump Game
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/jump-game/submissions/1929286588/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
