/*
 * Problem: 491. Non-decreasing Subsequences
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/non-decreasing-subsequences/submissions/1925717531/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) res.push_back(path);
        if (startIndex >= nums.size()) return;
        unordered_set<int> set;
        for (int i = startIndex; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end() || (!path.empty() && nums[i] < path.back())) continue; 
            set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};
