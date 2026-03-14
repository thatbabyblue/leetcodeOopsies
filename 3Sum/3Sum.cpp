/*
 * Problem: 3Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/3sum/description/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
