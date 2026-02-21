/*
 * Problem: 922. Sort Array By Parity II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/sort-array-by-parity-ii/submissions/1926712536/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIndex = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2) {
                while (nums[oddIndex] % 2) oddIndex += 2;
                swap(nums[i], nums[oddIndex]);
            }
        }
        return nums;
    }
};
