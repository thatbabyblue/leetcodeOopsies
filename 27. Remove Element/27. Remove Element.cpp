/*
 * Problem: 27. Remove Element
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-element/submissions/1942275995/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
