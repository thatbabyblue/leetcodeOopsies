/*
 * Problem: 167. Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1950651303/
 * Language: cpp
 * Date: 2026-03-17
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum = 0;
        for (int left = 0, right = numbers.size() - 1; left < right;) {
            sum = numbers[left] + numbers[right];
            if (sum == target) return vector<int>{1 + left, 1 + right};
            else if (sum < target) left++;
            else right--;
        }
        return vector<int>{0, 0};
    }
};
