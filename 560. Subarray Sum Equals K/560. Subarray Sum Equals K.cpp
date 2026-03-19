/*
 * Problem: 560. Subarray Sum Equals K
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/submissions/1952667557/
 * Language: cpp
 * Date: 2026-03-19
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = 1;
        int res = 0;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            res += seen[sum - k];
            seen[sum]++;
        }
        return res;
    }
};
