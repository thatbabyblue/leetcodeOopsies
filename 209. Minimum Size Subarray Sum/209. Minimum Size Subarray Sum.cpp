/*
 * Problem: 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1943558561/
 * Language: cpp
 * Date: 2026-03-10
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0;
        int sum = 0;
        int length = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                length = right - left + 1;
                res = length < res ? length : res;
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
