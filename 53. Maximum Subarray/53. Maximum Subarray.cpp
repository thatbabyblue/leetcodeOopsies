/*
 * Problem: 53. Maximum Subarray
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-subarray/submissions/1929247716/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res =  INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > res) res = count;
            if (count <= 0) count = 0;
        }
        return res;
    }
};
