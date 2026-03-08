/*
 * Problem: 26. Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1942282476/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
