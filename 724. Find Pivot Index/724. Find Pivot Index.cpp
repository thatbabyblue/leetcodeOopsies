/*
 * Problem: 724. Find Pivot Index
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-pivot-index/submissions/1926689910/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) {
            sum += a;
        }
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == sum - nums[i] - leftSum) return i;
            leftSum += nums[i];
            
        }
        return -1;
    }
};
