/*
 * Problem: 45. Jump Game II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/jump-game-ii/submissions/1929331681/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int res = 0;
        int curDis = 0;
        int nextDis = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDis = max(i + nums[i], nextDis);
            if (i == curDis) {
                res++;
                curDis = nextDis;
                if (curDis >= nums.size() - 1) break;
            }
        }
        return res;
    }
};
