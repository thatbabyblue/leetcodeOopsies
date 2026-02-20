/*
 * Problem: 90. Subsets II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/subsets-ii/submissions/1925691779/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        res.push_back(path);
        if (startIndex >= nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return res;
    }
};
