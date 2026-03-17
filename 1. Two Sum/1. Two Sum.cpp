/*
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/submissions/
 * Language: cpp
 * Date: 2026-03-17
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{i, map[target - nums[i]]};
            } else {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return vector<int>{0, 0};
    }
};
