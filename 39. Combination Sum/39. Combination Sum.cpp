/*
 * Problem: 39. Combination Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/combination-sum/submissions/1925052721/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};
