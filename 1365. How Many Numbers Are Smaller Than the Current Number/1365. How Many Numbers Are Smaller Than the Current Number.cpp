/*
 * Problem: 1365. How Many Numbers Are Smaller Than the Current Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/1925926950/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--) {
            hash[vec[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};
