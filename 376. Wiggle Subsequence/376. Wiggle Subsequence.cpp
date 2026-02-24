/*
 * Problem: 376. Wiggle Subsequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/wiggle-subsequence/submissions/1929221791/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        int preDiff = 0;
        int curDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};
