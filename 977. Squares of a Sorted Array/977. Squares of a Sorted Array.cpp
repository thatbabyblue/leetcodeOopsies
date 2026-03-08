/*
 * Problem: 977. Squares of a Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1942294235/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int q = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] <= nums[j] * nums[j]) {
                res[q--] = nums[j] * nums[j];
                j--;
            } else {
                res[q--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
